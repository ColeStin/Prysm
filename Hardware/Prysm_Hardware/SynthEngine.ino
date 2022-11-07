#include <SPI.h>
#include <string.h> //this library is used for test purposes only

using namespace std;


//sharp keys are designated by upper case letters where as lower case letters are normal values
//this is done because we wanted to keep them as chars so they did not take up too much RAM
char keyValues[18] = {'c','C','d','D','e','f','F','g','G','a','A','b','c','C','d','D','e','f'};

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
    int amount_of_vals = 18; //used for testing purposes
    int start_pin = 20; //used for testing purposes
    bool values[amount_of_vals] = {false}; //delcare an array of bools and set them all to false
    for(int i = start_pin; i<(start_pin + amount_of_vals); i++){//start a loop that will loop through all pin numbers

      //look at the current pin (20-38) and see if it is reading
      //set the bool value to the array instance for that pin (0-17)
      values[i-start_pin] = digitalRead(i) == LOW; 
    }
    
    //this section is for testing purposes only!!!!
    //it is used to generate a string to output to the terminal so that
    //we can see all the buttons being pressed.
    //it will more than double the run time of the program, so when demo-ing,
    //that needs to be accounted for
    String output= "[";
    for(int i = 0;i<amount_of_vals; i++){
      if(values[i] == "1"){
        //this if statement reads the value of the individual "key" within the array
        //that was generated in the previous loop, and adds its value to a string to output 
        //whether or not it was pushed

        //this will calculate the exact pin number and not just the instance in the loop 
        output = output + (i+start_pin) + ", ";
      }
    }
    output = output + "END]";
    //output the string to see which keys are being pressed
    Serial.println(output);
}
