A real-time gesture classification system built using an IR sensor and ESP32. This project detects and classifies three types of human gestures — pass, stay, and wave — using TinyML models trained on custom time-series sensor data.

It includes both:

✅ Local testing using Python + TensorFlow Lite

✅ On-device deployment using ESP32 with a Random Forest model (exported via EverywhereML)

📘 Problem Statement & Project Flow
Problem:
Detecting gesture types like passing, pausing, or waving is challenging using simple analog sensors. Traditional methods can't distinguish between these movements without complex camera systems or large models.

Goal:
To build a compact, accurate, and real-time gesture recognition system using:

Simple IR analog sensor

Lightweight ML model (Random Forest)

Real-time inference on ESP32

Approach Flow:
IR Sensor → ESP32 (ADC Readings) → Model Input (30 values) →
Local Inference (Python) / On-Device Inference (C++) → Gesture Output

🧪 Hardware & Connections
Microcontroller: ESP32 Dev Module

Sensor: IR analog sensor (e.g., TSOP or similar)

Connections:

Sensor OUT → GPIO34 (analog input)

GND and VCC to ESP32

Serial Connection: USB to Serial @ 9600 baud

📊 Data Collection
Collected 30 analog samples every 100 ms (3-second window)

Labeled 3 gestures:

pass – quick motion past sensor

stay – steady pause in front of sensor

wave – alternating high/low signals

Stored in gestures.csv

Each sample row: label, f1, f2, ..., f30

Values normalized to [0, 1]

💻 Model Training & Export
Training script: train_gesture_model.py

Library: everywhereml

Algorithm: RandomForestClassifier (10 trees)

Dataset split: 80% train / 20% test

Exported model as model.h

Achieved ~90.91% accuracy.
Model runs directly on microcontroller as C++ code — no conversion or TFLite required.

🧠 Local Inference (Python + TFLite)
Script: predict_ir_gesture.py

Model: ir_gesture_model.tflite

ESP32 sends 30 IR readings via Serial (COMx, 115200 baud)

Python receives data, runs inference, and prints predictions

Used for testing and validation before deployment.

🛠️ Deployment on ESP32
Arduino sketch: gesture_model.ino

Reads analog input from GPIO34

Feeds 30 readings into model.predict(input)

Outputs predicted gesture as label (pass, stay, or wave) via Serial

Runs every 3–5 seconds completely offline, using minimal memory.

📷 Sample Output (Serial Monitor)
markdown
Copy
Edit
✅ Model loaded. Starting prediction...
🔄 Collecting IR data...
🎯 Predicted gesture: 2 → wave
------------------------------
📚 Dependencies
Environment	Dependencies
PC (Python)	numpy, pyserial, tensorflow, everywhereml
ESP32	Arduino IDE only (no external libraries)
Hardware	ESP32 Dev Module, IR analog sensor

📈 Performance
Training Accuracy: ~90.91%

Model: Random Forest with 10 estimators

Inference Time: Near-instant on ESP32

Sampling: 30 values × 100 ms interval (3 seconds)

💡 Future Enhancements
Add OLED display or LED indicators for gesture feedback

Add gesture-based triggers (e.g., control lights, audio)

Train model for more gesture types

Use Edge Impulse for larger-scale retraining and deployment

📂 How to Run This Project
Clone this repository

Install dependencies:

Python: numpy, pyserial, tensorflow, everywhereml

Train the model using train_gesture_model.py

Test the model locally with predict_ir_gesture.py

Upload gesture_model.ino to ESP32 using Arduino IDE

Open Serial Monitor @ 9600 baud to view predictions



