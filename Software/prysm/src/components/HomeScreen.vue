<!-- Name of Artifact: HomeScreen.vue
    Summary: Vue files that is responsible for the display of our Home Screen
    including the title, background, nav bar, buttons, etc.
    Programmer's Name(s): Gage Burmaster, Alexander Wilhelm, Andrew Brown
    Date Code was Created: 9/15/2022 
    Date code was revised: 

       9/15 & 9/19 - Gage Burmaster - Creation of basic HTML format as well as
       styling and creation of JavaScript data functionality.

       9/19 & 20 - Gage Burmaster - Start of elementary front end display
       "Save File" and "New File" buttons created as well as "Save File" able to
       successfully open user's computer files to navigate file needed for upload.

       9/22 - Andrew Brown - Creation of nav bar with Prysm title at top of display.

       9/22 - Alexander Wilhelm - Update to Prysm title to be more UI friendly. Change
       to color scheme of front end, display increased in size, about button created on
       top right corner. Revision to background component to allow room for future GUI.

       9/25 - Andrew Brown - Fixed "info" icon which was not displaying right on run-time.
      Added documentation to describe buttons, title, info icon.

       9/25 - Alexander Wilhelm - Added entire prologue comments above with all dates
       and contributors for Sprint 1, as well as all descriptions of revisions. 
       Added additional documentation on HTML styling and JavaScript components.
-->

<template>
    <!-- Top navbar area to show name of app and soon to be info area button-->
    <div class="navbar">
      <div class="title">
        Prysm
        <!-- Info image which will soon link to about modal with credits to all makers of the project-->
        <img class="info" src="../../public/info_icon.png" alt="About"/>
      </div>
    </div>

    <!-- Main body which will contain wave table as well as buttons for user input-->
    <div class= "mainbody"> </div>

    <!-- Bottom section of file containing save and new file buttons-->
    <div class="background">
      <div class="save-button" @click="saveFile()">Save File</div>
      <div class="new-button" @click="newFile(data,file,type)">New File</div>
    </div>
</template>
      <!-- Below is creation of function for testing file saving with new file type
      we are implementing: ".prsm" -->
  <script>
  export default {
    data: function() {
      return {
        data: "the cat in the hat knows a lot about that",
        file: "waveform",
        type: ".prsm", //new file type for our wave tables
      }
    },
    methods: {
        increase() {
            this.data++;
        },
        //https://stackoverflow.com/questions/2897619/using-html5-javascript-to-generate-and-save-a-file
        saveFile() {    //Function to save waveform.prsm file to the computer
          console.log(this.$root);
          var pom = document.createElement('a');
          pom.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(this.data));
          pom.setAttribute('download', ""+this.file+this.type);

    if (document.createEvent) {
        var event = document.createEvent('MouseEvents');
        event.initEvent('click', true, true);
        pom.dispatchEvent(event);
    }
    else {
        pom.click(); //when button is clicked
    }
        },

      }
  }
  </script>
  <!-- HTML/CSS components of displaying and editing dimensions and colors of
       our nav bar at top of display, info icon, title, main body, background
       and the buttons displayed. 
  -->
  <style>
  .navbar {
    background-color: #3e4444;
    width: 100%;
    height: 65px;
    padding: 0px;
  }

  .info{
    height: 40px;
    width: 40px;
    margin-top: 12px;
    float: right;
  }

  .title{
    color: #e6e2d3;
    float: center;
    font-size: 50px;
    text-align: center;
    font-family: Impact;
    margin-left: 1%;
    margin-right: 1%;
  }

  .about {
    padding-left: 90%;
    margin-top: -33px;
    color: #e6e2d3;
    font-family: Impact;
  }

  .mainbody {
    background-color: #bdcebe;
    width: 100%;
    margin-top: 0px;
    height: 400px;
    padding: 4px;
  }

  .background {
    color: red;
    background-color: #3e4444;
    width: 100%;
    height: 100%;
  }
  
  .save-button{
    float: left;
    margin: auto;
    width: 8%;
    height: 8%;
    text-align: center;
    color: black;
    font-family: Impact;
    background-color: #b4a7d6ff;
    border: 2px solid #8e7cc3;
    padding: 4px;
    border-radius: 8px 8px ;
    cursor: pointer;
  }
  .new-button{
    float: right;
    margin: auto;
    width: 8%;
    height: 8%;
    text-align: center;
    color: black;
    font-family: Impact;
    background-color: #b4a7d6ff;
    border: 2px solid #8e7cc3;
    padding: 4px;
    border-radius: 8px 8px ;
    cursor: pointer;
  }
  </style>