<template>
    <div class="navbar">
      <div class="title">
        Prysm
      </div>
    </div>
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
        saveFile() {
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
    background-color: black;
    width: 100%;
    height: 25px;
    padding: 4px;

  }

  .title{
    color: #666665ff;
    float: left;
    text-align: center;
    font-family: Impact;
  }

  .background {
    color: red;
    background-color: #666665ff;
    width: 100%;
    height: 100%;
  }
  .save-button{
    margin: auto;
    width: 8%;
    text-align: center;
    color: black;
    background-color: #b4a7d6ff;
    border: 2px solid #8e7cc3;
    padding: 4px;
    border-radius: 8px 8px ;
    cursor: pointer;
  }
  .new-button{
    margin: auto;
    width: 8%;
    text-align: center;
    color: black;
    background-color: #b4a7d6ff;
    border: 2px solid #8e7cc3;
    padding: 4px;
    border-radius: 8px 8px ;
    cursor: pointer;
  }
  </style>