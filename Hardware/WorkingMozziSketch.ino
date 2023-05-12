#include <MozziGuts.h>
#include <mozzi_fixmath.h>
#include <Oscil.h>
#include <ADSR.h>
// #include <tables/sin2048_int8.h> // sine table for oscillator
// #include <tables/saw2048_int8.h>
#include <SD.h>
#include <SPI.h>

#define STOP_PIN 4
#define MAXOSC 4

#define ATTACK 10
#define DECAY 0
#define SUSTAIN 0
#define RELEASE 0
#define ATTACK_LEVEL 64
#define DECAY_LEVEL 0


struct Voice{
  Oscil<2048, AUDIO_RATE> osc;  // audio oscillator
  ADSR<CONTROL_RATE, AUDIO_RATE> env;  // envelope generator
  int note = 18;
  int play_index = -1;

};

Voice voices[MAXOSC];

bool previous[18] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
bool playing[18] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
float freq[18] = {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392, 415.30, 440, 466.16, 493.88, 523.25, 554.37, 587.33, 622.25, 659.25, 698.46};

//Voice *calc[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
int calc[MAXOSC] = {18,18,18,18};
int8_t * wavetable;
String global_currentFile = "/";


void switchFile(int upordown){

  File currentFile = SD.open(global_currentFile);

  String newFile = currentFile.openNextFile().name();

  currentFile.close();   
  global_currentFile = newFile;
  File dataFile = SD.open(newFile);
  int8_t shortforarray;
  bool booleanthing = true;
int arrayInc = 0;
            char * n = new char[8];
          int tmp1 = 0;
  // if the file is available, write to it:
  if (dataFile) {
    while (booleanthing &&  dataFile.available() ) {
      // Serial.println('1');
      char c = dataFile.read();
      if (c == '\n') {
      //we have hit the end of one input to our vector.
      char out[tmp1];
      for (int i = 0; i < tmp1; i++)
      {
        out[i] = n[i];
      }
      int tmp = atoi(out);
      shortforarray = tmp;
      wavetable[arrayInc] = shortforarray;
      shortforarray = 0;
      arrayInc++;
      tmp1=0;
      delete[] n;
      n = new char[8];
    } else if (c=='0' ||c=='.'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9' || c=='-' ){
      n[tmp1] = c;
      tmp1++;
// Serial.println("got here 2");      
    }
    else if (c == 'w' || c == 'W')
    {
      Serial.println("got here");
      dataFile.close();
      return;
    }
    else
    {
      Serial.println("something weird") ;
      booleanthing = false;
         }
    }
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening something");
  }
}



void fileToArray(){
   Serial.print("Initializing SD card...");
  int8_t shortforarray = 0;
  // see if the card is present and can be initialized:
  if (!SD.begin(53)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
File root = SD.open("/");
  String filename = root.openNextFile().name();
 filename = root.openNextFile().name();
 global_currentFile = filename;
  root.close();
  Serial.println(filename);
  File dataFile = SD.open(filename);
  bool booleanthing = true;
int arrayInc = 0;
            char * n = new char[8];
          int tmp1 = 0;
  // if the file is available, write to it:
  if (dataFile) {
    while (booleanthing &&  dataFile.available() ) {
      // Serial.println('1');
      char c = dataFile.read();
      if (c == '\n') {
      //we have hit the end of one input to our vector.
      char out[tmp1];
      for (int i = 0; i < tmp1; i++)
      {
        out[i] = n[i];
      }
      int tmp = atoi(out);
      shortforarray = tmp;
      wavetable[arrayInc] = shortforarray;
      shortforarray = 0;
      arrayInc++;
      tmp1=0;
      delete[] n;
      n = new char[8];
    } else if (c=='0' ||c=='.'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9' || c=='-' ){
      n[tmp1] = c;
      tmp1++;
// Serial.println("got here 2");      
    }
    else if (c == 'w' || c == 'W')
    {
      Serial.println("got here");
      dataFile.close();
      return;
    }
    else
    {
      Serial.println("something weird") ;
      booleanthing = false;
         }
    }
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening something");
  }
}





void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  wavetable = (int8_t*) calloc(2048,sizeof(int8_t));
  for (int i = 0; i < 2048; i++)
  {
    wavetable[i] = 0;
  }
  fileToArray();
  for (int i = 0; i < 2048; i++)
  {
    // Serial.println((long)&wavetable[i],HEX);
  }
  startMozzi(64);
  
  for(int i = 0; i < 18; i++)
  {
    pinMode(i+22, INPUT_PULLUP);
  }
  for(int i =0; i < MAXOSC; i++){
   // pinMode(22+i, INPUT_PULLUP);
    voices[i].env.setADLevels(ATTACK_LEVEL,DECAY_LEVEL);
    voices[i].env.setTimes(ATTACK,DECAY,SUSTAIN,RELEASE);
    // voices[i].osc.setTable(SIN2048_DATA);s
    voices[i].osc.setTable(wavetable);
    //voices[i].osc.setFreq(freq[i]);
  }
  
  
  
  //Serial.println("READY");
}

void loop() {
  // put your main code here, to run repeatedly:
  audioHook();
}

void turnOn(int i){
  //Serial.println(i);

  for(int j = 0; j<MAXOSC; j++){
    // Serial.println("NUMBERS");
    if(calc[j] == 18){
      voices[j].osc.setFreq(freq[i]);
      voices[j].env.noteOn();
      voices[j].play_index = j;
      voices[j].note = i;
      //Serial.println(voices[i])
      calc[j] = i;
      break;
      //Serial.println(calc[j]);
    }
  }
  //updateControl();
  //voices[0].env.noteOn();
}

void turnOff(int i){
  // voices[i].env.noteOff();
  // calc[voices[i].play_index] = 18;

  for(int j = 0; j < MAXOSC; j++)
  {
    if(calc[j] == i)
    {
      voices[j].env.noteOff();
      calc[j] = 18;
    }
    // voices[i].env.noteOff();
    // calc[voices[i].play_index] = 18;
  }

}



void updateControl(){
  for(int i = 0; i < 18; i++){
    bool pin = (digitalRead(22+i) == LOW);
    if(previous[i] == false && pin == true){
      //struct voice handle note on
      
      turnOn(i);
      //playing[i] = true;
    }
    else if(previous[i] == true && pin == false){
      //struct voice handle note off
      //helper(i, 0);
      turnOff(i);
      //playing[i] = false;
    }
    previous[i] = pin;
  }
}


int updateAudio(){
  int currentSample = 0;
  for(unsigned int i = 0; i < MAXOSC; i++){
    if(calc[i] != 18){
      //Serial.println(voices[i].note);
      currentSample += voices[i].env.next() * voices[i].osc.next();
      //currentSample += (*calc[i]).env.next() * (*calc[i]).osc.next();
      //Serial.println((calc[i])->env.next());
      //Serial.println(currentSample);
      //currentSample += voices[i].env.next() * voices[i].osc.next();
    }
  }
  //Serial.println(currentSample);
  return (int) (currentSample)>>8;
}