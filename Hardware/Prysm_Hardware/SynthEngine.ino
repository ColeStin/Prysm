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

  // for (int pinNumber = 20, pinNumber < 38, pinNumber++) //Sets up PIN Numbers 20 - 37
  // {
  //  pinMode(pinNumber, INPUT_PULLUP);
  // }

  //USE FOR LOOP LONG TERM

  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);

}

void loop() 
{

}
