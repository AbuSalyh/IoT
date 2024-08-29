#include <Keypad.h>
#include <Servo.h>

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Ultrasonic sensor pins
#define TRIG_PIN 10
#define ECHO_PIN 11

// Servo pin
#define SERVO_PIN 12

// Create objects
Servo doorServo;
long duration;
int distance;
int distanceThreshold = 5; // Default distance threshold in cm

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  doorServo.attach(SERVO_PIN);
  doorServo.write(0); // Initialize servo position (door closed)
}

void loop() {
  // Read ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0344 / 2; // Convert duration to distance in cm
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
  
  // Check distance and control servo
  if (distance <= distanceThreshold) {
    doorServo.write(90); // Open the door (servo angle 90 degrees)
    delay(3000); // Keep the door open for 2 seconds
    doorServo.write(0); // Close the door (servo angle 0 degrees)
  }
  
  // Check keypad input
  char key = keypad.getKey();
  if (key) {
    if (key >= '0' && key <= '9') {
      distanceThreshold = (distanceThreshold * 10) + (key - '0');
      Serial.print("Distance Threshold Set: ");
      Serial.println(distanceThreshold);
    } else if (key == '#') {
      // Confirm the threshold setting
      Serial.print("Distance Threshold Confirmed: ");
      Serial.println(distanceThreshold);
    } else if (key == '*') {
      // Reset the threshold to default value
      distanceThreshold = 10;
      Serial.println("Distance Threshold Reset to Default (5 cm)");
    }
  }
  
  delay(100); // Delay before the next reading
}
