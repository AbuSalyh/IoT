int LEDpin = 13;

void setup() 
{
pinMode(LEDpin, OUTPUT);
}

void loop() 
{
digitalWrite(LEDpin, HIGH);
delay(500);
digitalWrite(LEDpin, LOW);
delay(500);
}
