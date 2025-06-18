import serial
import numpy as np
import tensorflow as tf

# Path to your TFLite model
MODEL_PATH = "ir_gesture_model.tflite"
GESTURES = ["pass", "stay", "wave"]

# Load TFLite model and allocate tensors
interpreter = tf.lite.Interpreter(model_path=MODEL_PATH)
interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

# Setup serial connection
ser = serial.Serial('COM4', 115200)  # Replace COM5 with your port
print("Listening for IR data...")

while True:
    try:
        line = ser.readline().decode().strip()
        if not line or "," not in line:
            continue

        values = line.split(',')
        if len(values) != 30:
            print("⚠️ Incorrect number of values:", len(values))
            continue

        # Convert to float32 and normalize
        data = np.array([int(v) / 1023.0 for v in values], dtype=np.float32)
        data = data.reshape(1, 30)

        # Run inference
        interpreter.set_tensor(input_details[0]['index'], data)
        interpreter.invoke()
        output = interpreter.get_tensor(output_details[0]['index'])[0]

        # Show predictions
        print("Prediction:")
        for i, score in enumerate(output):
            print(f"{GESTURES[i]}: {score * 100:.2f}%")
        print("-" * 40)

    except KeyboardInterrupt:
        print("Stopped by user")
        break
    except Exception as e:
        print("Error:", e)
