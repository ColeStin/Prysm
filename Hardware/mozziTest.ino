/*  Example stopping Mozzi, which restores timers to previous states,
    so Arduino delay() and milleseconds() work, then resuming Mozzi again.

    This may be useful when using sensors or other libraries which need to use
    the same timers as Mozzi.  (Atmel Timer 0, Timer 1, and in HIFI mode, Timer 2).

    Circuit:
    Pushbutton on digital pin D4
       button from the digital pin to +5V (3.3V on Teensy 3.1)
       10K resistor from the digital pin to ground
    Audio output on digital pin 9 on a Uno or similar, or
    DAC/A14 on Teensy 3.1, or
    check the README or http://sensorium.github.io/Mozzi/

		Mozzi documentation/API
		https://sensorium.github.io/Mozzi/doc/html/index.html

		Mozzi help/discussion/announcements:
    https://groups.google.com/forum/#!forum/mozzi-users

    Tim Barrass 2013, CC by-nc-sa.
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h> // sine table for oscillator

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> bSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> cSin(SIN2048_DATA);

#define STOP_PIN 4

boolean pause_triggered, paused = false;;
unsigned int count = 0;
bool current[2] = {false, false};
bool previous[2] = {false, false};

void setup() {
  pinMode(22, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  aSin.setFreq(440); // set the frequency
  bSin.setFreq(220);
  cSin.setFreq(500);
  //startMozzi();
  Serial.begin(9600);
  Serial.println("READY");
}


void updateControl() {
  // if (digitalRead(STOP_PIN) == HIGH && pause_triggered == false) {
  //   pause_triggered = true;
  //   //count = 0;
  // }

  // if(digitalRead(STOP_PIN) == LOW){
  //   paused = false;
  // }
  // Serial.println("HERE");
  // if(!paused){
  //   Serial.println("Playing");
  //   return;
  // }

  // if(digitalRead(22) == HIGH && !pause_triggered){
  //   Serial.println("Pause not triggered and button not pressed");
  //   paused = true;
  // }
  // if(digitalRead(24) == HIGH && !pause_triggered){
  //   Serial.println("Pause not triggered and button not pressed");
  //   paused = true;
  // }

}


int updateAudio() {
  //return aSin.next();
  // int aNext = 0;
  // int bNext = 0;
  // for(int i = 0; i<2;i++){
  //   if(previous[i] == false && current[i] == true){
  //     return aSin.next();
  //   }
  //   else if(previous[i] == true && current[i] == false){
  //     return bSin.next();
  //   }
  // }

  if(digitalRead(22) == LOW && digitalRead(24) == LOW )
  {
    return aSin.next() + bSin.next() ;
 }
   if(digitalRead(22) == LOW)
  {
    return aSin.next();
  }
  else if(digitalRead(24) == LOW)
  {
    return bSin.next();
  }
  else if(digitalRead(23) == LOW)
  {
    return cSin.next();
  }

  //return aNext+bNext;

  // if(digitalRead(22) == LOW)
  // {
  // return aSin.next();
  // }

  // if(digitalRead(24) == LOW)
  // {
  // return bSin.next();
  // }
}


void loop() {

  //stopMozzi();
  
  // if (pause_triggered) {
  //   paused = true;
  //   pause_triggered = false;
  //   stopMozzi();
    
  // }

  // if (!paused && pause_triggered) {
  //   //Serial.println(count++);
  //   delay(100);
  //   //if (count > 10) {
  //     pause_triggered = false;
  //     startMozzi();
  //   //}
  // }

  // if(digitalRead(22) == LOW && !pause_triggered && paused){
  //   Serial.println("Pause not triggered and button pressed");
  //   pause_triggered = true;
  // }
  // else if(pause_triggered && digitalRead(22) == LOW){
  //   //aSin.setFreq(440);
  //   startMozzi();
  //   pause_triggered = false;
  //   paused = false;
  //   Serial.println("Pause triggered and button pressed");
  // }
  // else if(!paused && digitalRead(22) == HIGH){
  //   stopMozzi();
  //   pause_triggered = false;
  //   paused = true;
  //   Serial.println("Pause not triggered and button not pressed");
  // }

  //   //pin 24
  // if(digitalRead(24) == LOW && !pause_triggered && paused){
  //   Serial.println("Pause not triggered and button pressed");
  //   pause_triggered = true;
  // }
  // else if(pause_triggered && digitalRead(24) == LOW){
  //   //aSin.setFreq(220);
  //   startMozzi();
  //   pause_triggered = false;
  //   paused = false;
  //   Serial.println("Pause triggered and button pressed");
  // }
  // else if(!paused && digitalRead(24) == HIGH){
  //   stopMozzi();
  //   pause_triggered = false;
  //   paused = true;
  //   Serial.println("Pause not triggered and button not pressed");
  // }


  previous[0] = current[0];
  previous[1] = current[1];
  current[0] = (digitalRead(22) == LOW);
  current[1] = (digitalRead(24) == LOW);
  current[2] = digitalRead(23) == LOW;
  // Serial.print(previous[0]);
  // Serial.print(previous[1]);
  // Serial.print(current[0]);
  // Serial.print(current[1]);
  // Serial.println("");
  bool still_playing = false;
  bool start_playing = false;
  bool stop_playing = false;
  for(int i = 0; i<2;i++){
    if(previous[i] == false && current[i] == true){
      start_playing = true;
    }
    if(previous[i] == true && current[i] == false){
      stop_playing = true;

    }
    if(current[i] == true){
      still_playing = true;
    }
  }




  if(start_playing == true){
    if(paused == true){
      paused = false;
      Serial.println("START");
      startMozzi();
    }
    
    
  }
  if(stop_playing == true){
    if(!still_playing){
      if(paused == false){
        paused = true;
        Serial.println("STOP");
        stopMozzi();
      }
    }
  }


  if(!paused) audioHook();
}