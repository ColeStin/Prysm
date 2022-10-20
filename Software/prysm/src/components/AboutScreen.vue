<!-- Name of Artifact: HomeScreen.vue
    Summary: Vue files that is responsible for the display of our Home Screen
    including the title, background, nav bar, buttons, etc.
    Programmer's Name(s): Alexander Wilhelm, Andrew Brown
    Date Code was Created: 10/20/22
    Date code was revised: 
-->
<template>
  <div class="navbar">
    <div class="title">
      Prysm  
    </div>
  </div>

  <div class="mainbody">
       <h1> Contributors: </h1>  
       
       <p>Andrew Brown, Gage Burmaster, Dominic D'Attilio, Cole Stinson, Alexander Wilhelm</p>
        
        <h1> Project Description: </h1>

        <p> This project was created during our EECS 581 & EECS 581 Senior Computer Science Capstone classes at
        The University of Kansas in both Fall 2022 & Spring 2023. </p>

        <p> This desktop app is a companion app to go with the physical synthesizer we produced. It is a wavetable generator and will load the generated tables onto an SD card and allow our synthesizer
        to read these wavetables and generate sounds to the users liking. The user can upload a wave table to be used on the actual synthesizer. </p>

        <h1>GitHub Link: </h1>
        
        <p>The GitHub link to our code as well as commit information can be found at the below GitHub Link: </p>
        <p> https://github.com/ColeStin/Prysm </p>

       <!--  Implement close button  -->    
          <div class="goBack" @click="goBack()">Go Back</div> 
    </div> 

 </template>

 <script>
    
export default {
    
    methods: {
    
        goBack() { //brings user back to MainScreen
         //add MainScreen component on App.vue
        //remove AboutScreen component on App.vue
        }

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

.title {
  color: #e6e2d3;
  float: center;
  font-size: 50px;
  text-align: center;
  font-family: Impact;
  margin-left: 1%;
  margin-right: 1%;
}

.mainbody {
  background-color: #bdcebe;
  width: 100%;
  margin-top: 0px;
  height: 550px;
  padding: 4px;
}

.background {
  color: red;
  background-color: #3e4444;
  width: 100%;
  height: 100%;
}

.goBack {
  width: 16%;
  height: 20%;
  text-align: center;
  margin: auto;
  margin-top: 10px;
  color: black;
  font-family: Impact;
  font-size: 40px;
  background-color: #FDDB93;
  border: 2px solid black;
  padding: 4px;
  border-radius: 8px 8px;
  cursor: pointer;
}

</style>

