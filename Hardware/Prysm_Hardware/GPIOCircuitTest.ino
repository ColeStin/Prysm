#include <SPI.h>

using namespace std;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(12) == LOW)
  {
    Serial.println("12");
  }
  else if(digitalRead(9) == LOW)
  {
    Serial.println("9");
  }

  if(analogRead(A0) == 50)
  {
    Serial.println("knob read");
  }
  
}
