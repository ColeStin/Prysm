<!-- Name of Artifact: InstructionsScreen.vue
    Summary: Vue file that is responsible for the display of our Instructions Screen
    that explains how to utilize the Prysm desktop app.
    Programmer's Name(s): Alexander Wilhelm
    Date Code was Created: 10/20/22
    Date code was revised: 11/21/22 - Alex - Revision of Documentation & Organization 
-->
<template>
    <div class="aboutbody">

        <div class="headerLabel">
          <h1> Wavetable </h1>
        </div>

        <div class="headerLabel">
          <h1> Add Point: </h1>
        </div>

        <div class="headerLabel">
          <h1> Delete Point: </h1>
        </div>
        
        <div class="headerLabel">
          <h1> New File: </h1>
        </div>
        <div class="headerLabel">
          <h1> Open File: </h1>
        </div>

        <div class="headerLabel">
          <h1> Save File: </h1>
        </div>

        <div class="headerLabel">
          <h1> Curve Slider: </h1>
        </div>

        <div class="headerLabel">
          <h1> X value Slider: </h1>
        </div>

        <div class="headerLabel">
          <h1> Y value Slider: </h1>
        </div>
    </div>
  
   </template>
  
   <script>
      
  export default {
      
      methods: {}
  }
  
  </script>
   
   <style>
  
   .p {
      color: black;
   }
  
   .p2 {
    visibility: hidden;
  }
  
  .aboutbody a:link
  {
    text-decoration: none;
    color: white;
    margin-right: 10%;
  }
  
  .aboutbody {
    font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
    background-image: url("../../Images/aboutBackground2.png");
    background-size: cover;
   /* background-color: #97b4b3; */
    width: 100%;
    height: 975px;
    padding: 4px;
  }
  
  .h1 {
    font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
    text-align: left;
  }
  
  .headerLabel {
  margin-left: 46%;
  border-radius: 50px;
  background-color: #3188c6;
  padding: 0px;
  margin-bottom: 20px;
  width: 7%;
  height: 4%;
  }
  
  .headerLabel2 {
  margin-left: 44.5%;
  border-radius: 50px;
  background-color:  #3188c6;
  padding: 0px;
  margin-bottom: 20px;
  width: 10%;
  height: 4%;
  }
  
  .headerLabel3 {
  margin-left: 41.5%;
  border-radius: 50px;
  background-color: #333333;
  padding: 0px;
  margin-bottom: 0px;
  width: 15%;
  height: 6%;
  }
  
  .headerLabel3:hover {
    background-color: red;
  }
  
  .headerLabel h1{
  color:white;
  font-size: 18px;
  }
  
  .headerLabel2 h1{
  color:white;
  font-size: 18px;
  }
  
  .headerLabel3 h1{
  color:white;
  font-size: 30px;
  }
  
  </style>
  
  