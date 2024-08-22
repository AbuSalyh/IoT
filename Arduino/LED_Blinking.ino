int pwm=11;
void setup () {
  pinMode (pwm, OUTPUT);

}
  // put your setup code here, to run once:

void loop() {
  // put your main code here, to run repeatedly:
analogWrite (pwm,64);
delay(500);
analogWrite (pwm,127);
delay(500);
analogWrite (pwm,191);
delay(500);
analogWrite (pwm,255);
delay(500);
analogWrite (pwm,0);
delay(5000);
}
