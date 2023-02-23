/*
** File Name: SynthEngine.ino
** Description: File for Arduino with synth engine stuff
** Created By: Dom D'Attilio
** Edited By: Dom D'Attilio, Cole Stinson, Gage Burmaster
** Last Edit: 2-23-23 Gage Burmaster - organized code, moved init to init function
*/


#include <ArduinoSTL.h>
#include <SPI.h>
#include <string.h> //this library is used for test purposes only
#include <cmath>
#include <vector>
#include <SD.h>


using namespace std;

//global variable declaration
//Will store all of the oscillator frequencies created
Oscillator[18] oscArray;
//sharp keys are designated by upper case letters where as lower case letters are normal values


//this is done because we wanted to keep them as chars so they did not take up too much RAM
char keyValues[18] = {'c','C','d','D','e','f','F','g','G','a','A','b','c','C','d','D','e','f'};
//the arrays of keys for the current and previous cycles to check whether to start, get sample, or stop
bool* current_playing = NULL;
bool* previous_playing = NULL;
//use pointers so you can easily swap the previous and current without having to move all values over




/*****************************************************************************************************************/
//This is the class for the oscillators
class Oscillator{
  public:
  //constructor for oscillator object. takes a keyNumber for example 40 for C4 to calculate frequency and set it to member variable
      Oscillator(float keyNumber, std::vector<float> waveTable)
      {
        //calculates frequency for 12 tone temperament use A4 as reference note with value 440Hz
        waveTable = waveTable;
        oscFrequency = 440*pow(static_cast<float>(2),((keyNumber - static_cast<float>(49))/static_cast<float>(12)));
      }

      //gets 1 sample of oscillator and advances index
      float getSample()
      {
         if(isPlaying()){
          index = std::fmod(index, static_cast<float>(waveTable.size()));
          const auto sample = interpolate();
          index += indexIncrement;
         }
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
      int sampleRate = 64;
      float oscFrequency;
      float index = 0.f;
      float indexIncrement = 0.f;
      std::vector<float> waveTable;
};


char getKey(int pinVal)
{
  pinVal = pinVal-20;
  return keyValues[pinVal % 18];
}

/********************************************************************************************************************************/

//In Filing 
//THis function reads in a file, parses it, and adds the data to a vector. It is then called in setup() to create the vector we are using in the synth engine
std::vector<float> fileToVector()
{
    std::vector<float> tmpVector;
 
  File root = SD.open("/");
  String filename = root.openNextFile().name();
  File file = SD.open(filename);
  if (!file) Serial.println("FILE CANNOT BE OPENED");
  char line[20];
  int n = 0;
  char * val;
  // read lines from the file
  while (file.available()){
    //add characters to our buf
    //UNTIL you hit a newline, then reset

    char c = file.read();
    if (c == '\n') {
      //we have hit the end of one input to our vector.
      char out[n];
      for (int i = 0; i < n; i++)
      {
        out[i] = line[i];
      }
      float tmp = atof(out);
      tmpVector.push_back(tmp);
      Serial.println(out);
      n=0;
    } else {
      line[n] = c;
      n++;

    }
  }
  Serial.println("FILE HAS BEEN READ");



    return tmpVector;
}


void setup() {

  //initailize the current_playing var
  current_playing = (bool*) malloc(18*sizeof(bool));

  //definitely need to come back to this
  for(int i= 40; i<58; i++)
  {
    //push back onto oscillator vector
  
    //is this line real code??  
    Oscillator newOscillator = Oscillator(i, wavetable);
    oscArray[i-40]=newOscillator;
  }

  

  
  
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
  
  //Do we need to store the result of this somewhere???
  fileToVector();
}

void loop() 
{
    //first free up previous_playing
    free(previous_playing);
    //reallocate whatever was in current_playing into previous_playing
    previous_playing = (bool*) realloc (current_playing, 18*sizeof(bool));

    //re-initalize current_playing  
    current_playing = (bool*) malloc(18*sizeof(bool));


    int amount_of_vals = 18; //used for testing purposes
    int start_pin = 20; //used for testing purposes
    bool values[amount_of_vals] = {false}; //delcare an array of bools and set them all to false
    for(int i = start_pin; i<(start_pin + amount_of_vals); i++){//start a loop that will loop through all pin numbers

      //look at the current pin (20-38) and see if it is reading
      //set the bool value to the array instance for that pin (0-17)
      *current_playing[i-start_pin] = digitalRead(i) == LOW; 
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
