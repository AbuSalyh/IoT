int irpin=7;


void setup() {
  // put your pinsetup code here, to run once:

pinMode(irpin, INPUT);
Serial.begin(9600);
}

void loop() 
  
  {   
    int irvalue= digitalRead(irpin);
    Serial.print("Show irvalue=");
    Serial.println(irvalue);
    delay(500);
  }
  
