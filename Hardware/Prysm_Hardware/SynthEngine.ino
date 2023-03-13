/*
** File Name: SynthEngine.ino
** Description: File for Arduino with synth engine stuff
** Created By: Dom D'Attilio
** Edited By: Dom D'Attilio, Cole Stinson, Gage Burmaster
** Last Edit: 2-23-23 Gage Burmaster - organized code, moved init to init function
** Edited 2-26: Added 4 functions, render, processor, keyHandler, handleEvent -- Dom D'Attilio
*/


#include <ArduinoSTL.h>
#include <SPI.h>
#include <string.h> //this library is used for test purposes only
#include <cmath>
#include <vector>
#include <SD.h>
#include <Adafruit_MCP4725.h>

using namespace std;

// Adafruit_MCP4725 dac;

float *  wavetableArray = new float[1000];

/*****************************************************************************************************************/
//This is the class for the oscillators
class Oscillator{
  public:
  //constructor for oscillator object. takes a keyNumber for example 40 for C4 to calculate frequency and set it to member variable
      Oscillator(float keyNumber)
      {
        Serial.println(F("NEW OSC"));
        //calculates frequency for 12 tone temperament use A4 as reference note with value 440Hz
       /* for (int i = 0; i < 50; i++)
        {
        //Serial.println(i);
        waveTable.push_back(i);
        }*/
       
        ////Serial.println("WAVE TABLE SAVED");

        //oscFrequency = 440*pow(static_cast<float>(2),((keyNumber - static_cast<float>(49))/static_cast<float>(12)));
        ////Serial.println("FREQUENCY SAVED");
      }

      //gets 1 sample of oscillator and advances index
      float getSample()
      {
         if(isPlaying()){
          index = std::fmod(index, 1000);
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

      void start()
      {
       // indexIncrement = oscFrequency * static_cast<float>(waveTable.size()) / static_cast<float>(sampleRate);
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
        const auto truncatedIndex = static_cast<float>(index);
        const auto nextIndex = static_cast<int>(std::ceil(index)) % 1000;
        const auto nextIndexWeight = index - static_cast<float>(truncatedIndex);
        return wavetableArray[std::ceil(index)] * nextIndexWeight + (1.f - nextIndexWeight) * wavetableArray[std::floor(truncatedIndex)];
      }
    //private member variables
      int sampleRate = 1000;
      float oscFrequency;
      float index = 0.f;
      float indexIncrement = 0.f;
      //std::vector<float> waveTable;
      //float WaveTable[1000];
};


/**************************************************************************************************************************************/

//global variable declaration
//Will store all of the oscillator frequencies created

Oscillator * oscArray[18];



//global variable for waveTable, will be filled in setup() with result of infile
std::vector<float> waveTableVector;

//vector for storing samples
std::vector<float> sampleVector;

//sharp keys are designated by upper case letters where as lower case letters are normal values
//this is done because we wanted to keep them as chars so they did not take up too much RAM
char keyValues[18] = {'c','C','d','D','e','f','F','g','G','a','A','b','c','C','d','D','e','f'};
//the arrays of keys for the current and previous cycles to check whether to start, get sample, or stop
bool* current_playing = NULL;
bool* previous_playing = NULL;
//use pointers so you can easily swap the previous and current without having to move all values over







char getKey(int pinVal)
{
  pinVal = pinVal-20;
  return keyValues[pinVal % 18];
}

/********************************************************************************************************************************/

//In Filing 
//THis function reads in a file, parses it, and adds the data to a vector. It is then called in setup() to create the vector we are using in the synth engine
void fileToArray() {

// //Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(53)) {
    ////Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  ////Serial.println("card initialized.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
File root = SD.open("/");
  String filename = root.openNextFile().name();
 filename = root.openNextFile().name();
  root.close();
  ////Serial.println(filename);
  File dataFile = SD.open(filename);

    bool booleanthing = true;
    int arrayInc = 0;
    char * n = new char[20]; 
    int tmp1 = 0;
  // if the file is available, write to it:
  if (dataFile) {
    while (booleanthing &&  dataFile.available() ) {
      // ////Serial.println('1');
      char c = dataFile.read();
      if (c == '\n') {
      //we have hit the end of one input to our vector.
      char out[tmp1];
      for (int i = 0; i < tmp1; i++)
      {
        out[i] = n[i];
      }
      float tmp = atof(out);
      wavetableArray[arrayInc] = tmp;
      arrayInc++;
      tmp1=0;
      delete[] n;
      n = new char[20];
    } else if (c=='0' ||c=='.'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9' ){
      n[tmp1] = c;
      tmp1++;
// ////Serial.println("got here 2");      
    }
    else if (c == 'w' || c == 'W')
    {
      booleanthing = false;
      // ////Serial.println(F("got here"));
      dataFile.close();
      // Serial.println(F("got here again"));
      return;
    }
    else
    {
      ////Serial.println("something weird") ;
      booleanthing = false;
         }
    }
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    ////Serial.println("error opening datalog.txt");
  }


}


/************************************************************************************************/
//Process BLock Function, will be called in loop. This is the main code for taking a key press and calling the necessary methods to follow
void processor()
{
  auto currSample = 0;

  for(int i = 0; i< 18; i++)
  {
    render(currSample, currSample + 1);
    currSample = currSample + 1;
    handleEvent(i);
  }


  render(currSample, sampleVector.size());
}


/************************************************************************************************/
//gets samples from all active oscillators
void render(int startSample, int endSample)
{
  for(auto& Oscillator : oscArray)
  {
    if (Oscillator->isPlaying())
    {
      for(int sample = startSample; sample < endSample; ++sample)
      {
        sampleVector.push_back(Oscillator->getSample());
      }
    }
  }
}


/**************************************************************************************************/
//This turns the oscillator on off depending on if it isPlaying returns true or not
void handleEvent(int i)
{
  if(oscArray[i]->isPlaying())
  {
    oscArray[i]->start();
  }
  else
  {
    oscArray[i]->stop();
  }
}




/**********************************************************************************************/
//this updates currentPLaying buffer depending on if its reading high or low, high being key is pressed = 1, low being not pressed = 0
void keyHandler()
{
  for(int i = 22; i <40; i++){
    if(digitalRead(i) == HIGH){   //Button is not being pressed
      current_playing[i-20] = 0;
    }else{                        //Button is being pressed
      current_playing[i-20] = 1;
    }
  }

}



/**********************************************************************************************/

void setup() {
  Serial.begin(9600);



  // waveTableVector = fileToVector();
  //initailize the current_playing var
  //   current_playing = (bool*) malloc(18*sizeof(bool));
  while (!Serial) {
true;    
  }

   
    fileToArray();
    Serial.println("how this");
  //   //definitely need to come back to this
  for( int i = 0; i < 18; i++){
    Serial.println(F("inside initialization"));
        oscArray[i] = new Oscillator(i+40);


    }
    Serial.println("ALL OSCS CREATED");

  

  
  
  

  // for (int pinNumber = 20, pinNumber < 38, pinNumber++) //Sets up PIN Numbers 20 - 37
  // {
  //  pinMode(pinNumber, INPUT_PULLUP);
  // }

  //USE FOR LOOP LONG TERM

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
  pinMode(38, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);
  

  // dac.begin(0x62);


    Serial.println("here");
  //Do we need to store the result of this somewhere???
  
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
    int start_pin = 22; //used for testing purposes
    bool values[amount_of_vals] = {false}; //delcare an array of bools and set them all to false
    keyHandler();
    processor();
    float freq = 0.f;
    for (auto x : sampleVector)
    {
      freq += x;
    }


    // dac.setVoltage(freq,false);












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
    //////Serial.println(output);

}