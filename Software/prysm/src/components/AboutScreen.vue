<!-- Name of Artifact: AboutScreen.vue
    Summary: Vue file that is responsible for the display of our About Screen
    including the credits of our desktop app from a development aspect.
    Programmer's Name(s): Alex
    Date Code was Created: 10/20/22
    Date code was revised:
    11/21/22 - Alex - Revision of Documentation & Organization 
    12/4/22 - Alex - Code Refactoring
      
-->

<template>
  <div class="aboutbody">
      
      <div class="headerMain">
        <h1> Contributors: </h1>  
      </div>
       <p>Andrew Brown, Gage Burmaster, Dominic D'Attilio, Cole Stinson, Alexander Wilhelm</p>
        
      <div class="headerMain2">
        <h1> Project Description: </h1>  
      </div>
        <p> This project was created during our EECS 581 & EECS 582 Senior Computer Science Capstone classes at
        The University of Kansas in both Fall 2022 & Spring 2023. </p>
        &nbsp;
        <p> Prysm desktop app is a companion app to go with the physical synthesizer we produced. It is a wavetable
        generator and will load the generated tables onto an SD </p>
        <p> card and allow our synthesizer
        to read these wavetables and generate sounds to the users liking. The user can upload a wave table to be used on the actual synthesizer. </p>

      <div class="headerGitHub">    
        <a href="https://github.com/ColeStin/Prysm">
          <!-- <p> &nbsp; </p> -->
          <h1> Visit Prysm GitHub</h1>
        </a>
      </div>
      <p> The GitHub link to our code as well as commit information can be found at the above GitHub Link. </p> 
              
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
  padding: 4px;
}

.aboutbody a:link
{
  text-decoration: none;
  color: white;
  margin-right: 10%;
}

.headerMain {
margin-left: 44.5%;
border-radius: 50px;
background-color:  #3188c6;
padding: 0px;
margin-bottom: 20px;
width: 10%;
height: 2.5%;
}

.headerMain h1{
color:white;
font-size: 18px;
}

.headerMain2 {
margin-left: 44.5%;
border-radius: 50px;
background-color:  #3188c6;
padding: 0px;
margin-bottom: 20px;
width: 10%;
height: 4.5%;
}

.headerMain2 h1{
color:white;
font-size: 18px;
}

.headerGitHub {
margin-left: 41.5%;
border-radius: 50px;
background-color: #333333;
padding: 0px;
margin-bottom: 0px;
width: 13%;
height: 4%;
}

.headerGitHub:hover {
  background-color: red;
}

.headerGitHub h1{
  color:white;
  font-size: 20px;
}

.h1 {
  font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
  text-align: left;
}

</style>

