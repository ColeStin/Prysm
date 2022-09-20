<template>
    <div class="background">
      <div class="save-button" @click="saveFile()">Save File</div>
      <div class="new-button" @click="newFile()">New File</div>
    </div>
  </template>
  
  <script>
  export default {
    data: function() {
      return {
        data: 0,
      }
    },
    methods: {
        increase() {
            this.data++;
        },
        saveFile() {

        }

      }
  }
  </script>
  
  <style>
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