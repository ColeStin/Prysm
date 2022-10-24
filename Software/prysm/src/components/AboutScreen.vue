<!-- Name of Artifact: HomeScreen.vue
    Summary: Vue files that is responsible for the display of our Home Screen
    including the title, background, nav bar, buttons, etc.
    Programmer's Name(s): Alexander Wilhelm, Andrew Brown
    Date Code was Created: 10/20/22
    Date code was revised: 
-->
<template>
  <div class="mainbody">
       <h1> Contributors: </h1>  
       
       <p>Andrew Brown, Gage Burmaster, Dominic D'Attilio, Cole Stinson, Alexander Wilhelm</p>
        
        <h1> Project Description: </h1>

        <p> This project was created during our EECS 581 & EECS 582 Senior Computer Science Capstone classes at
        The University of Kansas in both Fall 2022 & Spring 2023. </p>
        <p>______________________________________________________________________________________________________________________________________</p>
        <p> Prysm desktop app is a companion app to go with the physical synthesizer we produced. It is a wavetable
        generator and will load the generated tables onto an SD </p>
        <p> card and allow our synthesizer
        to read these wavetables and generate sounds to the users liking. The user can upload a wave table to be used on the actual synthesizer. </p>

        <h1>GitHub Link: </h1>
        
        <p>The GitHub link to our code as well as commit information can be found at the below GitHub Link: </p>
        <p>  <a href="https://github.com/ColeStin/Prysm">Visit Prysm GitHub</a> </p>

    </div> 

 </template>

 <script>
    
export default {
    
    methods: {
    

    }
}

</script>
 
 <style>

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

.h1 {
  text-align: left;
}

</style>

