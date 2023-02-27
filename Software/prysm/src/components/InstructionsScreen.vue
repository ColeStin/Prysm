<!-- Name of Artifact: InstructionsScreen.vue
    Summary: Vue file that is responsible for the display of our Instructions Screen
    that explains how to utilize the Prysm desktop app.
    Programmer's Name(s): Alex
    Date Code was Created: 10/20/22
    Date code was revised: 11/21/22 - Alex - Revision of Documentation & Organization
    11/24/22 - Alex - Text created for instructions page and change in styling.
-->
<template>
    <div class="aboutbody">

        <h1> How To Use Prysm: </h1>
        <div class="headerLabel">
            <h1> Wavetable: </h1>
        </div>
        <p> The wavetable is a configurement of certain lines, points, and curves that can be edited to create </p>
        <p> different sounds on the Prysm synthesizer when the different buttons on the physical Synthesizer are pressed. </p>
        <p>&nbsp;</p>

        <div class="headerLabelFile">
          <h1> New File
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-file-earmark-plus-fill" viewBox="0 0 16 16">
            <path d="M9.293 0H4a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h8a2 2 0 0 0 2-2V4.707A1 1 0 0 0 13.707 4L10 .293A1 1 0 0 0 9.293 0zM9.5 3.5v-2l3 3h-2a1 1 0 0 1-1-1zM8.5 7v1.5H10a.5.5 0 0 1 0 1H8.5V11a.5.5 0 0 1-1 0V9.5H6a.5.5 0 0 1 0-1h1.5V7a.5.5 0 0 1 1 0z"/>
            </svg>
          </h1>
        </div>
        <p>
            This button will reset the wavetable to its original state.
        </p>
        <p>&nbsp;</p>

          <div class="headerLabelFile">
          <h1> Open File
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-files" viewBox="0 0 16 16">
            <path d="M13 0H6a2 2 0 0 0-2 2 2 2 0 0 0-2 2v10a2 2 0 0 0 2 2h7a2 2 0 0 0 2-2 2 2 0 0 0 2-2V2a2 2 0 0 0-2-2zm0 13V4a2 2 0 0 0-2-2H5a1 1 0 0 1 1-1h7a1 1 0 0 1 1 1v10a1 1 0 0 1-1 1zM3 4a1 1 0 0 1 1-1h7a1 1 0 0 1 1 1v10a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1V4z"/>
            </svg>
          </h1>
        </div>
        <p>
            This button will open a .prsm file to load an already edited wavetable for further editing.    
        </p>
        <p>&nbsp;</p>

        <div class="headerLabelFile">
          <h1> Save File
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-file-earmark-arrow-down-fill" viewBox="0 0 16 16">
            <path d="M9.293 0H4a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h8a2 2 0 0 0 2-2V4.707A1 1 0 0 0 13.707 4L10 .293A1 1 0 0 0 9.293 0zM9.5 3.5v-2l3 3h-2a1 1 0 0 1-1-1zm-1 4v3.793l1.146-1.147a.5.5 0 0 1 .708.708l-2 2a.5.5 0 0 1-.708 0l-2-2a.5.5 0 0 1 .708-.708L7.5 11.293V7.5a.5.5 0 0 1 1 0z"/>
            </svg>
          </h1>
        </div>
        <p> This button will save an edited wavetable to be opened/edited later by creating a .prsm file. </p>

        There is also a textbox right before it if you would like to name this file before it is downloaded.
 
        <h1> Function - Minimum - Maximum: </h1>
         

        <p> <b> Function: </b> This slider will graph the function given (use equation like y = "7x + 3" for example) onto the entire wavetable. </p>
 
        <p> <b> Minimum: </b> This will decide the initial starting point of the equation to be graphed. </p>

        <p> <b> Maximum: </b> This value will decide the initial ending point of the equation to be graphed. </p>
    </div>
  
   </template>
  
   <script>
      
  export default {
      
      methods: {}
  }
  
  </script>
   
  <style>

    .aboutbody {
      font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
      background-image: url("../../Images/aboutBackground2.png");
      background-size: cover;
      width: 100%;
      height: 1200px;
      padding: 4px;
    } 

    .aboutbody .p
    {
      color: white;
    }
    
    .h1 {
      font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
      text-align: left;
    }

    .imgLabel
    {
      margin-right: 68%;
    }
    
    .headerLabel {
    margin-left: 7%;
    border-radius: 15px 15px;
    background-color: #3188c6;
    padding: 0px;
    margin-bottom: -50px;
    width: 9%;
    height: 3%;
    }

    .headerLabel h1{
      color:white;
      font-size: 18px;
    }
    
    .headerLabelFile {
    margin-left: 7%;
    border-radius: 15px 15px;
    background-color: #333333;
    padding: 0px;
    margin-bottom: -50px;
    width: 8%;
    height: 3%;
    color: white;
    font-size: 9px;
    }

    .headerLabelFile:hover {
    background-color: red;
    }

    .headerLabelAdd {
    margin-left: 7%;
    border-radius: 15px 15px;
    background-color: #95B8D1;
    padding: 0px;
    margin-bottom: -50px;
    width: 9%;
    height: 3%;
    color: white;
    font-size: 9px;
    }

    .headerLabelAdd:hover {
      background-color: #6050DC;
    }
    
    .headerLabelDelete {
    margin-left: 7%;
    border-radius: 15px 15px;
    background-color: #EDAFB8;
    margin-bottom: -50px;
    width: 9%;
    height: 3%;
    color: white;
    font-size: 9px;
    }

    .headerLabelDelete:hover {
      background-color: #AA0000;
    }
  
  </style>
  
  