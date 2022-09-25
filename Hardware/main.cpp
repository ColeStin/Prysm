/**
 * Name of Artifact: Main.cpp
 * Summary: Main c++ file for use by hardware, has a main and helper functions to be called in main
 * Programmer's Name(s): Dom D'Attilio, Cole Stinson
 * Date Code was Created: 9/22/2022 - Dom D'Attilio
 * Date code was revised: 
 *      9/24 - Cole Stinson - Added keypress functionality
 *      9/25 - Dom D'Attilio - Added documentation
 * 
 * 
 * 
 */



#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int keypress(){
    system ("/bin/stty raw") //allows raw access to the terminal
    int c;
    system ("/bin/stty -echo") //starts to look at the text functinos of the terminal
    c = getc(stdin) //grabs the text input
    system ("/bin/stty echo") //stops looking at the text functions of the terminal
    system ("/bin/stty cooked") //this will reset the terminal behavior
    return c;
}




int main()
{
    while(true){
        int key = keypress();
        std::cout<<"key : "<<key<<'\n';
        if(key == 97) break;
    }
    return 0
}




