<template>
    <!-- Top navbar area to show name of app and soon to be info area button-->
    <div class="navbar">
      <div class="title">
        Prysm 
      </div>
      <div class = "about">
         <img src="aboutLogo.jpg" alt="About"/>
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
  
  <script>
  export default {
    data: function() {
      return {
        data: "the cat in the hat knows a lot about that",
        file: "waveform",
        type: ".prsm",
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
        pom.click();
    }
        },

      }
  }
  </script>
  
  <style>
  .navbar {
    background-color: #3e4444;
    width: 100%;
    height: 65px;
    padding: 0px;
  }

  .title{
    color: #e6e2d3;
    float: center;
    font-size: 50px;
    text-align: center;
    font-family: Impact;
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