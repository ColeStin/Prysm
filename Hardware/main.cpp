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





void outputHandler(int pinIn)
{
    //will work on this tomorrow

    std::cout << "Pin Number " << pinIn << " was activated\n";
}