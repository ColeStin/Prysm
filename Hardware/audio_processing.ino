https://github.com/adafruit/Adafruit_MCP4725

https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

Basics of Tone :
if(need to play){
    tone(pin #, frequency value, *OPTIONAL* duration in miliseconds)
    cannot generate notes less than 31hz
    pin needs to be on PWM output pin
}
else(not playing){
    notone(pin #)
}



MCP4725 Basics : this code will not compile
#include <Adafruit_MCP4725.h>
#include <Wire.h> //not sure what this does
int wave_table[] //this needs to be your wave table or sin wave

in setup: 
    dac.begin(0x62) // this is the dac's address (default)

in loop:
    //loop through the wave table
    for (int i = 0; i < wave_table_length; i++){
        dac.setVoltage(wave_table[i], false)
        //dac.setVoltage will set the voltage of the dacs output
        delayMicroseconds(microsecond) // this may be able to be used to generate the
                                       // frequency but we were not able to pin down the
                                       // ratio between microseconds and frequency
    }


useful link from a forum about voltage to frequency
https://forum.arduino.cc/t/voltage-to-frequency/236192