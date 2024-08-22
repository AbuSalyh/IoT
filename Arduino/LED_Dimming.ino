int pwm=11;

void setup () 
{
  pinMode (pwm, OUTPUT);
}

void loop() 
{
for(int i=0; i<=100; i++)
{
  analogWrite (pwm,1);
  delay(100);
}

for (int i=255; i>=0; i--)
{
  analogWrite(pwm,i);
  delay(100);
}
}
