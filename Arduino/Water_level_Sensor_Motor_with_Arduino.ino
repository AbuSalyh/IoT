int waterSensorPin = A0;  // Analog pin for the water level sensor
int relayPin1 = 2;        // Relay control pin for Channel 1
int relayPin2 = 3;        // Relay control pin for Channel 2 (not used)

void setup() {
  Serial.begin(9600);       // Start serial communication
  pinMode(relayPin1, OUTPUT);  // Set relay pin 1 as an output
  pinMode(relayPin2, OUTPUT);  // Set relay pin 2 as an output
  digitalWrite(relayPin1, LOW); // Ensure relay 1 is off initially
  digitalWrite(relayPin2, LOW); // Ensure relay 2 is off initially
  Serial.println("Water Level Monitoring with Motor Control");
}

void loop() {
  int sensorValue = analogRead(waterSensorPin);  // Read the water sensor value

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue <= 500) {
    Serial.println("Water Level: Empty");
    digitalWrite(relayPin1, HIGH);  // Turn the motor ON
  } 
  else if (sensorValue > 500 && sensorValue <= 600) {
    Serial.println("Water Level: Low");
    digitalWrite(relayPin1, HIGH);  // Turn the motor ON
  } 
  else if (sensorValue > 600 && sensorValue <= 800) {
    Serial.println("Water Level: Medium");
    digitalWrite(relayPin1, LOW);   // Turn the motor OFF
  } 
  else if (sensorValue > 600) {
    Serial.println("Water Level: High");
    digitalWrite(relayPin1, LOW);   // Turn the motor OFF
  }

  delay(1000); // Wait for 1 second before the next reading
}
