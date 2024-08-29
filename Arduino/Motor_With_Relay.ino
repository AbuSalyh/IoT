int relay1 = 2;
int relay2 = 3;

void setup() {
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
Serial.begin(9600);
Serial.println("Motor Direction of Rotation");
Serial.println("Using 2 Relays");
delay(2000);
}

void loop() {
digitalWrite(relay1, LOW);
digitalWrite(relay2, HIGH);
Serial.println("Rotating in CCW");
delay(3000);

// stop the motor
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
Serial.println("Stopped");
delay(2000);

// Rotate in CW direction
digitalWrite(relay1, HIGH);
digitalWrite(relay2, LOW);
Serial.println("Rotating in CW");
delay(3000);

// stop the motor
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
Serial.println("Stopped");
delay(2000);

Serial.println("===============");
}