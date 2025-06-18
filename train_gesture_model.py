from everywhereml.data import Dataset
from everywhereml.sklearn.ensemble import RandomForestClassifier

# Load dataset with label column specified
dataset = Dataset.from_csv('gestures.csv', target_column='label')

# Split dataset (train=80%, test=20%)
train, test = dataset.split(0.8)

# Train Random Forest
model = RandomForestClassifier(n_estimators=10)
model.fit(train.X, train.y)

# Evaluate model
accuracy = model.score(test.X, test.y)
print(f"✅ Accuracy: {accuracy * 100:.2f}%")

# Export Arduino-ready header
model.to_arduino_file('model.h')
