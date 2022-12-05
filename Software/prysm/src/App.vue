<!-- Name of Artifact: App.vue
    Summary: Sets up app with front, color, and merges components
    to all work together in final display.
    Programmer's Name(s): Gage Burmaster, Alex Wilhelm
    Date Code was Created: 9/15/2022 
    Date code was revised: 
     9/25 - Alexander Wilhelm - Prologue documentation
     10/20 - Alexander Wilhelm - Added AboutScreen switching
     12/4 - Alex - Refactoring of code
-->
<template>
  <div class="navbar">
    <div class="title"> 
      Prysm

      <!-- AboutScreen Navigation System--> 
      <img v-if = "!aboutClicked" class="about" @click = "aboutClicked = true, instructionsClicked = false" src="../Images/info_icon.png" alt="About"/> 

      <!-- InstructionScreen Navigation System--> 
      <img v-if = "!instructionsClicked" class="instructions" @click = "aboutClicked = false, instructionsClicked = true" src="../Images/instructions_icon.png" alt="About"/> 

      <!-- HomeScreen Navigation System--> 
       <img v-if = "aboutClicked && !instructionsClicked" class="goBack" @click = "aboutClicked = false, instructionsClicked = false" src="../Images/back.png" alt="Go Back" />
       <img v-if = "!aboutClicked && instructionsClicked" class="goBack2" @click = "aboutClicked = false, instructionsClicked = false" src="../Images/back.png" alt="Go Back" />

    </div>
  </div>

  <!--If conditions met, displays certain screen --> 
  <HomeScreen v-if = "!aboutClicked && !instructionsClicked"></HomeScreen> 
  <AboutScreen v-if = "aboutClicked && !instructionsClicked"></AboutScreen>
  <InstructionsScreen v-if = "!aboutClicked && instructionsClicked"></InstructionsScreen>

</template>

<script>

import HomeScreen from './components/HomeScreen.vue'
import AboutScreen from './components/AboutScreen.vue'
import InstructionsScreen from './components/InstructionsScreen.vue'

export default {

data: function () {
  return {
    instructionsClicked: false,
    aboutClicked: false
  };
},
name: 'App',
components: {
  HomeScreen, AboutScreen, InstructionsScreen
},
methods: {}
}
</script>

<style>

#app {
font-family: Avenir, Helvetica, Arial, sans-serif;
-webkit-font-smoothing: antialiased;
-moz-osx-font-smoothing: grayscale;
text-align: center;
color: #2c3e50;
}

.navbar {
background-color: #3e4444;
width: 100.5%;
height: 150px;
padding: 0px;
}

.title {
color: #e6e2d3;
float: center;
font-size: 70px;
padding: 25px;
text-align: center;
font-family: Impact;
margin-left: 2.5%
}

.about {
  margin-top: 1%;
  height: 60px;
  width: 60px;
  float: right;
  cursor: pointer;
}

.instructions {
  margin-top: 1%;
  height: 50px;
  width: 50px;
  padding: 5px;
  float: left;
  cursor: pointer;
}

.goBack {
  margin-top: 1%;
  height: 60px;
  width: 60px;
  float: right;
  cursor: pointer;
}

.goBack2 {
  margin-top: 1%;
  height: 60px;
  width: 60px;
  float: left;
  cursor: pointer;
}

</style>