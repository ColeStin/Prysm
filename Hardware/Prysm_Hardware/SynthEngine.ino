#include <SPI.h>
using namespace std;

char keyValues[18] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F"};

char getKey(int pinVal)
{
  pinVal = pinVal-20;
  return keyValues[pinVal % 18];
}

void setup() {
  Serial.begin(9600);

 
}

void loop() {

}
