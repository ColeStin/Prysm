#include <SPI.h>
#include <SD.h>

using namespace std;

class FileHandler{
  public:
    FileHander(){
      size++;
      allFilePaths = new String[size];
    };
    ~FileHandler(){
      delete allFilePaths;
    };
    void addFile(String filepath){
      size++;
      String * new_allFilePaths = new String[size];
      if(!new_allFilePaths){ //check to make sure that the board can handle the amount of strings we give it
        Serial.print("The board has run out of space!!\nPlease remove any unused files from the SD card.");
      }
      for(int i = 0; i <size-1; i++){
        new_allFilePaths[i] = allFilePaths[i]; //loop through each entry and copy it to the new array
      }
      allFilePaths = new_allFilePaths; //replace old array with new array
    };
  private:
    String * allFilePaths;
    uint8_t size; 
};

File currentFile;
File root;

FileHandler files;

//these take up storage space
int inPinOne = A0; //pin A0
int inPinTwo = A1; //pin A1
int inPinThree = A2; //pin A2
int inPinFour = A3; //pin A3
int inPinFive = A4; //pin A4


void setup() {
  Serial.begin(115200);

  while (!Serial); //only needed for native usb boards

  Serial.print("Initializing SD Card...");
  if(!SD.begin(10)){ //s tarts at pin 10 for CS, cspin is optional
    Serial.println("Initialization Failed!\n\n");
    Serial.println("Is your card inserted...?");
    Serial.println("Try powering off, inserting the card, and turning the power back on.");
    while (true); //loop to not cause problems to SD card, essentially just sit here in this state
  }
  Serial.println("initialization Done!");
  root = SD.open("/"); //open the root directory of the SD card
  fileTrace(root); //start mapping the files
  Serial.println("Setup Complete! Happy button mashing");


  //this is a test to see how many we can have
  files.addFile("/dir/1.prsm");
  files.addFile("/dir/2.prsm");
  files.addFile("/dir/3.prsm");
  files.addFile("/dir/4.prsm");
  files.addFile("/dir/2ffd.prsm");
  // files.addFile("/dir/2sdfsd.prsm");
  // files.addFile("/dir/2fdsfd.prsm");
  // files.addFile("/dir/2sdfsd.prsm");
  // files.addFile("/dir/sdfsdfsdfsdf2.prsm");
  // files.addFile("/dir/sdfsdf2.prsm");
  // files.addFile("/dir/sfddfsfsf2.prsm");
  // files.addFile("/dir/ddfsdsfsdfsdfs2.prsm");
  // files.addFile("/dir/sdfsd2.prsm");
  // files.addFile("/dir/dsfdfs2.prsm");
  // files.addFile("/dir/sfsfefs2.prsm");
  // files.addFile("/dir/2.prsm");
  // files.addFile("/dir/dfsdf2.prsm");
  // files.addFile("/dir/2.prsm");
  // files.addFile("/dir/asdfadfasdfasdfasdfadfadfadfadfas2.prsm");
  // files.addFile("/dir/asdfasdfasdfadfadfadfafdadfadfadf2.prsm");
  // files.addFile("/dir/sdfdsfdsfd2.prsm");
  // files.addFile("/dir/dsfsd2.prsm");
  // files.addFile("/dir/sdfds2.prsm");
  // files.addFile("/dir/asdfasdfasdfasdfasdfadfadfasdfasdfa2.prsm");
  // files.addFile("/dir/asdfasdfsadfasdfasdfasdfsadadfadfaadafds2.prsm");
  // files.addFile("/dirasdfasdfasdfasdfafadfasdfadadfadfadfa/2.prsm");
  // files.addFile("/dirasdfasdfasdfasdfadfadfasdfassdfsasdfadf/2.prsm");
  // files.addFile("/diasasdfdfadr/2.prsm");
  // files.addFile("/dir/2asdf.prsm");
  // files.addFile("/dirdfs/2asdf.prsm");
  // files.addFile("/dirdfffes/2.prsm");
  // files.addFile("/dir/asdfdfsd2.prsm");
  // files.addFile("/dirdfd/2.prsm");
  // files.addFile("/dir/sdf2.prsm");
  // files.addFile("/dir/sdddf2.prsm");
  // files.addFile("/dir/2ff.prsm");
  // files.addFile("/dir/2sdffsd.prsm");
  // files.addFile("/dirsggsdgd/2.prsm");
  // files.addFile("/dirsdgsgsdse/2.prsm");
  // files.addFile("/dirasdgasdgasdg/2.prsm");
  // files.addFile("/dirgasdga/2.prsm");
  //Arduino Mega - 5% of Storage and 24% of Dynamic Memory
  //Arduino Uno  - 44% of Storage and 99% of Dynamic Memory

  //set input pins to read input
  pinMode(inPinOne, INPUT); //pull up resistor is turned off
  pinMode(inPinTwo, INPUT); //pull up resistor is turned off
  digitalWrite(inPinTwo, HIGH); //turn on the pullup resistor and make it always read high
  pinMode(inPinThree, INPUT); //Specify 
  pinMode(inPinFour, INPUT);
  pinMode(inPinFive, INPUT);

}

//this function will loop over all files on the sd card and add all .prsm files to the FileHandler for later use, it does call itself
void fileTrace(File dir){
  while(true){ //go forever to capture all files
    File entry = dir.openNextFile(); //opens the next file in the current directory 
    if(!entry){
      //there are no more files left in this directory, break out of this loop and end function for this directory
      break;
    }
    String currentEntryName = entry.name(); //grab the file name to attach to end of filepath or to send to filehandler
    
     
    if(entry.isDirectory()){
      //current file being pointed at is a directory
      fileTrace(entry); //navigate through this current directory being pointed at
    } 
    else{
      //do substring and find to see if it is a .prsm file
      uint8_t dotPos = currentEntryName.indexOf('.'); //find the position of the period in the filename
      if(currentEntryName.substring(dotPos) == ".prsm"){
        //it is a file that we want
        Serial.println(currentEntryName);
        //files.addFile(currentEntryName); //add the file path to the list of all .prsm file
      }
    }
    entry.close(); //always close the file ur looking at :)
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(inPinOne) == HIGH){ //the pin is pressed. Pull up resistor is turned off
    //do something if the button is pressed
    Serial.write("Button One has been pressed!");
  }
  if(digitalRead(inPinTwo) == LOW){ //the pin is pressed but the pull up resistor is turned on so the value will be inverse
    Serial.write("Button two has been pressed!");
  }
}

