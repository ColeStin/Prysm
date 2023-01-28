/*
** File Name: SynthEngine.ino
** Description: File for Arduino with synth engine stuff
** Created By: Dom D'Attilio
** Edited By: Dom D'Attilio, COle Stinson
** Last Edit: 12-2 Dom D'Attilio - Added oscillator functionality
*/






#include <SPI.h>
#include <string.h> //this library is used for test purposes only
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;






/*****************************************************************************************************************/
//This is the class for the oscillators
class Oscillator{

  public:
  //constructor for oscillator object. takes a keyNumber for example 40 for C4 to calculate frequency and set it to member variable
      Oscillator(int keyNumber)
      {
        //calculates frequency for 12 tone temperament use A4 as reference note with value 440Hz
        oscFrequency = 440*pow(2,(keyNumber - 49)/12);
      }

      //gets 1 sample of oscillator and advances index
      float getSample()
      {
          jassert(isPlaying());
          index = std::fmod(index, static_cast<float>(waveTable.size()));
          const auto sample = interpolateLinearly();
          index += indexImplement;
      }

      //stops sampling, resets indexes to 0
      void stop()
      {
        index = 0.f;
        indexIncrement = 0.f;
      }

      //determines if oscillator is getting sample, if indexIncrement equals 0, its not running
      bool isPlaying() const
      {
        return indexIncrement != 0.f;
      }

  private:
     //interpolate between values in wave table
      float interpolate() const
      {
        const auto truncatedIndex = static_cast<typename  decltype(waveTable)::size_type>(index);
        const auto nextIndex = static_cast<typename  decltype(waveTable)::size_type>(std::ceil(index)) % waveTable.size();
        const auto nextIndexWeight = index - static_cast<float>(truncatedIndex);
        return waveTable[index] * nextIndexWeight + (1.f - nextIndexWeight) * waveTable[truncatedIndex];
      }
    //private member variables
      double oscFrequency;
      float index = 0.f;
      float indexIncrement = 0.f;
      std::vector<float> waveTable;
};

/********************************************************************************************************************************/

//In Filing 
std::vector<float> fileToVector(std::string input)
{
    std::vector<float> tmpVector;
   std::ifstream inFile;
	inFile.open(input);
	if (!inFile.is_open())
	{
		//error handle
        return tmpVector;
	}
    std::string stringRead;
    float tmpFloat =0;
    int size;
    inFile >> stringRead;
    inFile >> size;
    int i = 0;
    while (i > size)
    {
        inFile >> tmpFloat;
        tmpVector.push_back(tmpFloat);

    }
	
    inFile.close();
    return tmpVector;
}
/*****************************************************************************************/



//sharp keys are designated by upper case letters where as lower case letters are normal values
//this is done because we wanted to keep them as chars so they did not take up too much RAM
char keyValues[18] = {'c','C','d','D','e','f','F','g','G','a','A','b','c','C','d','D','e','f'};

char getKey(int pinVal)
{
  pinVal = pinVal-20;
  return keyValues[pinVal % 18];
}



void setup() {

  //definitely need to come back to this
  for(int i= 40; i<58; i++)
  {
    Oscillator newOscillator(i)
  }

  std::vector<float> pointVector = fileToVector();
  
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
