#include <MozziGuts.h>
#include <mozzi_fixmath.h>
#include <Oscil.h>
#include <ADSR.h>
#include <tables/sin2048_int8.h> // sine table for oscillator
#include <tables/saw2048_int8.h>


#define STOP_PIN 4
#define MAXOSC 4

#define ATTACK 10
#define DECAY 0
#define SUSTAIN 0
#define RELEASE 0
#define ATTACK_LEVEL 64
#define DECAY_LEVEL 0


struct Voice{
  Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> osc;  // audio oscillator
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





void setup() {
  // put your setup code here, to run once:

  startMozzi(64);
  
  for(int i = 0; i < 18; i++)
  {
    pinMode(i+22, INPUT_PULLUP);
  }
  for(int i =0; i < MAXOSC; i++){
   // pinMode(22+i, INPUT_PULLUP);
    voices[i].env.setADLevels(ATTACK_LEVEL,DECAY_LEVEL);
    voices[i].env.setTimes(ATTACK,DECAY,SUSTAIN,RELEASE);
    voices[i].osc.setTable(SIN2048_DATA);
    //voices[i].osc.setFreq(freq[i]);
  }
  
  
  Serial.begin(9600);
  //Serial.println("READY");
}

void loop() {
  // put your main code here, to run repeatedly:
  audioHook();
}

void turnOn(int i){
  //Serial.println(i);
  int activeOsc = 0;
  for(int j = 0; j<MAXOSC; j++){
    Serial.println("NUMBERS");
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

    voices[0].osc.setFreq(freq[i]);
    voices[0].env.noteOn();
    voices[0].play_index = 0;
    voices[0].note = i;
    calc[0] = i;

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