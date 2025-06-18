import csv
import re

# Each gesture is assigned a label: 0 for pass, 1 for stay, 2 for wave
RAW_DATA = {
    "stay": {
        "label": 1,
        "logs": """
            12:56:11.850 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:56:19.836 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:56:27.858 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:56:35.843 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:56:43.855 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:56:51.847 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:56:59.850 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:57:07.818 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:57:15.821 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:57:23.829 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:57:31.842 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            12:57:39.850 -> 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        """
    },
    "pass": {
        "label": 0,
        "logs": """
            13:02:36.346 -> 1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1
            13:02:43.075 -> 1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,0,0,1,1,1,0,1,0,1,1,1,0,0,1,1
            13:02:51.104 -> 0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1
            13:02:59.068 -> 1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,1
            13:03:07.057 -> 0,1,1,1,1,0,0,1,0,1,1,0,1,1,0,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1
            13:03:15.069 -> 0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,1,0,0,1,0,0,1,1,1,1,1
            13:03:23.087 -> 1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,0,1,1,0
            13:03:31.070 -> 1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1,1
            13:03:39.048 -> 1,1,0,1,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1
            13:03:47.066 -> 1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0
            13:03:55.069 -> 1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0
            13:04:03.067 -> 1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1
            13:04:11.070 -> 0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0
            13:04:19.078 -> 0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0
            13:04:27.040 -> 1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0
            13:04:35.070 -> 1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1
            13:04:43.066 -> 1,0,1,0,0,1,1,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0
            13:04:51.072 -> 0,1,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,0,1,0,1,1,1
            13:04:59.078 -> 1,0,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,0,0,0,1,0,0,1,0
            13:05:07.070 -> 0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,1,0,1,1,0,1
            13:05:15.068 -> 1,1,0,0,1,1,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,0,0,0
        """
    },
    "wave": {
        "label": 2,
        "logs": """
            13:11:12.612 -> 1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0
            13:11:20.620 -> 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1
            13:11:28.628 -> 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
            13:11:36.622 -> 0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1
            13:11:44.613 -> 0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1
            13:11:52.626 -> 0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1
            13:12:00.609 -> 1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0
            13:12:08.611 -> 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0
            13:12:16.625 -> 1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1
            13:12:24.627 -> 0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0
            13:12:32.588 -> 0,1,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0
            13:12:40.631 -> 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0
            13:12:48.633 -> 1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0
            13:12:56.621 -> 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0
            13:13:04.613 -> 0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1
            13:13:12.594 -> 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1
            13:13:20.631 -> 0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1
            13:13:28.606 -> 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
            13:13:36.628 -> 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0
        """
    }
}

# The number of sensor readings expected for each gesture sample
NUM_SENSORS = 30
# The name of the output CSV file
OUTPUT_CSV_FILE = 'gestures.csv'

def process_logs_to_dataset(raw_data, num_sensors):
    """
    Parses raw log strings, cleans them, and formats them into a list of lists.
    
    Args:
        raw_data (dict): A dictionary containing the gesture logs and labels.
        num_sensors (int): The expected number of readings per sample.

    Returns:
        list: A list of lists representing the structured dataset.
    """
    dataset = []
    
    # Process each gesture type (stay, pass, wave)
    for gesture, data in raw_data.items():
        label = data["label"]
        logs = data["logs"].strip().split('\n')
        
        print(f"Processing gesture: '{gesture}' with label: {label}")
        
        for line in logs:
            # Clean up the line by removing leading/trailing whitespace
            line = line.strip()
            if not line:
                continue

            # Use regex to find the comma-separated data part of the line
            match = re.search(r'->\s*([\d,]+)', line)
            if match:
                readings_str = match.group(1)
                
                # Split into individual readings and convert to integers
                try:
                    readings = [int(val) for val in readings_str.split(',')]
                except ValueError:
                    print(f"  - Skipping malformed line: {line}")
                    continue
                
                # Pad the readings if the sample is shorter than expected
                if len(readings) < num_sensors:
                    padding_needed = num_sensors - len(readings)
                    readings.extend([0] * padding_needed)
                    print(f"  - Padded a sample from {len(readings)-padding_needed} to {num_sensors} readings.")

                # Truncate the readings if the sample is longer than expected
                elif len(readings) > num_sensors:
                    readings = readings[:num_sensors]
                    print(f"  - Truncated a sample from {len(readings)} to {num_sensors} readings.")

                # Add the label to the end of the readings list
                readings.append(label)
                dataset.append(readings)

    return dataset

def write_csv(dataset, filename, num_sensors):
    """
    Writes the processed dataset to a CSV file.
    
    Args:
        dataset (list): The list of gesture samples.
        filename (str): The path to the output CSV file.
        num_sensors (int): The number of sensor readings.
    """
    # Create the header row for the CSV file
    header = [f'reading_{i+1}' for i in range(num_sensors)] + ['label']
    
    try:
        with open(filename, 'w', newline='') as csvfile:
            csv_writer = csv.writer(csvfile)
            
            # Write the header first
            csv_writer.writerow(header)
            
            # Write the data rows
            csv_writer.writerows(dataset)
            
        print(f"\nSuccessfully created dataset with {len(dataset)} samples.")
        print(f"File saved as '{filename}'")

    except IOError as e:
        print(f"\nError: Could not write to file '{filename}'.")
        print(f"Reason: {e}")

# --- Main execution ---
if __name__ == "__main__":
    # Process the raw logs
    gesture_dataset = process_logs_to_dataset(RAW_DATA, NUM_SENSORS)
    
    # Write the processed data to a CSV file
    if gesture_dataset:
        write_csv(gesture_dataset, OUTPUT_CSV_FILE, NUM_SENSORS)
    else:
        print("No data was processed. The CSV file was not created.")

