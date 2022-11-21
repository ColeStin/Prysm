<!-- Name of Artifact: AboutScreen.vue
    Summary: Vue file that is responsible for the display of our About Screen
    including the credits of our desktop app from a development aspect.
    Programmer's Name(s): Alexander Wilhelm
    Date Code was Created: 10/20/22
    Date code was revised: 11/21/22 - Alex - Revision of Documentation & Organization 
-->
<template>
  <div class="aboutbody">
      
      <div class="headerLabel">
        <h1> Contributors:
        </h1>  
      </div>
       
       <p>Andrew Brown, Gage Burmaster, Dominic D'Attilio, Cole Stinson, Alexander Wilhelm</p>
        
      <div class="headerLabel2">
        <h1> Project Description: </h1>  
      </div>

        <p> This project was created during our EECS 581 & EECS 582 Senior Computer Science Capstone classes at
        The University of Kansas in both Fall 2022 & Spring 2023. </p>
        <p2>&nbsp;</p2>
        <p> Prysm desktop app is a companion app to go with the physical synthesizer we produced. It is a wavetable
        generator and will load the generated tables onto an SD </p>
        <p> card and allow our synthesizer
        to read these wavetables and generate sounds to the users liking. The user can upload a wave table to be used on the actual synthesizer. </p>

        <p>&nbsp;</p>

       <div class="headerLabel3">    
          <a href="https://github.com/ColeStin/Prysm">
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
  height: 750px;
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

