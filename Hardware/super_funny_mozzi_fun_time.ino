
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
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> dSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> eSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> fSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> gSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> hSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> iSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> jSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> kSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> lSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> mSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> nSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> oSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> pSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> qSin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> rSin(SIN2048_DATA);

#define STOP_PIN 4

boolean pause_triggered, paused = false;;
unsigned int count = 0;
bool previous[18] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
bool playing[18] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
bool freq[18] = [220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390]

void helper(int index, int freq){
  switch(index){
        case 0:
          aSin.setFreq(freq);
          break;
        case 1:
          bSin.setFreq(freq);
          break;
        case 2:
          cSin.setFreq(freq);
          break;
        case 3:
          dSin.setFreq(freq);
          break;
        case 4:
          eSin.setFreq(freq);
          break;
        case 5:
          fSin.setFreq(freq);
          break;
        case 6:
          gSin.setFreq(freq);
          break;
        case 7:
          hSin.setFreq(freq);
          break;
        case 8:
          iSin.setFreq(freq);
          break;
        case 9:
          jSin.setFreq(freq);
          break;
        case 10:
          kSin.setFreq(freq);
          break;
        case 11:
          lSin.setFreq(freq);
          break;
        case 12:
          mSin.setFreq(freq);
          break;
        case 13:
          nSin.setFreq(freq);
          break;
        case 14:
          oSin.setFreq(freq);
          break;
        case 15:
          pSin.setFreq(freq);
          break;
        case 16:
          qSin.setFreq(freq);
          break;
        case 17:
          rSin.setFreq(freq);
          break;        
      }
}


void setup() {

  startMozzi();
  pinMode(22, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  
  for(int i = 0, i < 18; i++){
    helper(i, freq[i]);
  }
  
  Serial.begin(9600);
  Serial.println("READY");
}

void updateControl(){
  for(int i = 0; i < 18; i++){
    bool pin = digitalRead(22+i);
    if(previous[i] == false && pin == true){
      helper(i, freq[i]);
    }
    else if(previous[i] == true && pin == false){
      helper(i, 0);
    }
  } 
}

int updateAduio(){
  int sum = 0;
  // if(playing[0] == true){
  //   sum += aSin.next();
  // }
  // if(playing[1] == true){
  //   sum += bSin.next();
  // }
  // if(playing[2] == true){
  //   sum += cSin.next();
  // }
  // if(playing[3] == true){
  //   sum += dSin.next();
  // }
  // if(playing[4] == true){
  //   sum += eSin.next();
  // }
  // if(playing[5] == true){
  //   sum += fSin.next();
  // }
  // if(playing[6] == true){
  //   sum += gSin.next();
  // }
  // if(playing[7] == true){
  //   sum += hSin.next();
  // }
  // if(playing[8] == true){
  //   sum += iSin.next();
  // }
  // if(playing[9] == true){
  //   sum += jSin.next();
  // }
  // if(playing[10] == true){
  //   sum += kSin.next();
  // }
  // if(playing[11] == true){
  //   sum += lSin.next();
  // }
  // if(playing[12] == true){
  //   sum += mSin.next();
  // }
  // if(playing[13] == true){
  //   sum += nSin.next();
  // }
  // if(playing[14] == true){
  //   sum += oSin.next();
  // }
  // if(playing[15] == true){
  //   sum += pSin.next();
  // }
  // if(playing[16] == true){
  //   sum += qSin.next();
  // }
  // if(playing[17] == true){
  //   sum += rSin.next();
  // }

  sum = aSin.next() + bSin.next() + cSin.next() + dSin.next() + 
          eSin.next() + fSin.next() + gSin.next() + hSin.next() +
          iSin.next() + jSin.next() + kSin.next() + lSin.next() + 
          mSin.next() + nSin.next() + oSin.next() + pSin.next() +
          qSin.next() + rSin.next();

  return sum >> 4;
}


void loop(){
  audioHook();
}