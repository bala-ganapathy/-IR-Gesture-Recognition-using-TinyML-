#include "model.h"

RandomForestClassifier model;
float input[30];
const char* labels[] = {"pass", "stay", "wave"};

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("✅ Model loaded. Starting prediction...");
}

void loop() {
  Serial.println("🔄 Collecting IR data...");


  for (int i = 0; i < 30; i++) {
    input[i] = analogRead(34) / 4095.0f;  
    delay(100);  
  }

  int prediction = model.predict(input);

  Serial.print("🎯 Predicted gesture: ");
  Serial.print(prediction);
  Serial.print(" → ");
  Serial.println(labels[prediction]);

  Serial.println("------------------------------");
  delay(3000);  
}
