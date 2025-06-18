import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split

# Load the dataset
df = pd.read_csv("C:/Personal/TinyML integration/gestures.csv")  # Replace with actual filename

# Separate features and labels
X = df.drop("label", axis=1).values.astype(np.float32)  # 30 sensor readings
y = df["label"].values.astype(np.int32)                 # class labels (0, 1, 2)

# Split into train and test (80/20)
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, shuffle=True, random_state=42
)

# Print shape for verification
print("Train features:", X_train.shape)
print("Test features:", X_test.shape)
print("Train labels:", y_train.shape)
print("Test labels:", y_test.shape)
