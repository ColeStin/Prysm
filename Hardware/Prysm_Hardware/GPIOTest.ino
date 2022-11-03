/**
 * Name of Artifact: GPIOTest.ino
 * Summary: File to test functionality of GPIO pins on Arduino Board
 * Programmer's Name(s): Dom D'Attilio
 * Date Code was Created: 10/8/2022 - Dom D'Attilio
 * Date code was revised: 
 *     10/8 - Dom D'Attilio - File created
 *     10/10 - Dom D'Attilio - setup and loop functions written
 *     10/11 - Dom D'Attilio - documentation completed
 * 
 * 
 * 
 * 
 */


#include <SPI.h>
#include <SD.h>

using namespace std;


/**
 * Function: setup
 * Description: Setup function to initialize pins and other necessary board functionality
 * Pre/Post conditions: None
 * Arguments: None
 * Potential Errors: None
*/
void setup(){
    //initializes 4 gpio digital pins as input pins
    pinMode(12, INPUT_PULLUP); //Alex, replicate this
    pinMode(11, INPUT);
    pinMode(10, INPUT);
    pinMode(9, INPUT);



}




/**
 * Function: loop
 * Description: Main function that continuously loops, contains digital read for pins
 * Pre/Post conditions: None
 * Arguments: None
 * Potential Errors: None
*/
void loop()
{
    val12 = digitalRead(12);
    val11 = digitalRead(11);
    val10 = digitalRead(10);
    val9 = digitalRead(9);

    if(val12 == HIGH) Serial.println("Button 12 was pressed");
    if(val11 == HIGH) Serial.println("Button 11 was pressed");
    if(val10 == HIGH) Serial.println("Button 10 was pressed");
    if(val9 == HIGH) Serial.println("Button 9 was pressed");
}