<!-- Name of Artifact: App.vue
    Summary: Sets up app with front, color, and merges components
    to all work together in final display.
    Programmer's Name(s): Gage Burmaster, Alex Wilhelm
    Date Code was Created: 9/15/2022 
    Date code was revised: 
     9/25 - Alexander Wilhelm - Prologue documentation
     10/20 - Alexander Wilhelm - Added AboutScreen switching
     11/21 - Alexander Wilhelm - Added InstructionScreen switching
-->
<template>
    <div class="navbar">
      <div class="title"> 
        Prysm
      <!-- Info image which will link to about page which credits to all makers of the project-->
      <img v-if = "!aboutClicked && !instructionsClicked" class="about" @click = "aboutClicked = true, instructionsClicked = false" src="../Images/info_icon.png" alt="About"/> 
       <!-- <div class = "about" v-if = "!iconClicked" @click= "iconClicked = true">About</div>  -->

       <!-- Instructions image which will link to instructions page which explains how to utilize software--> 
      <img v-if = "!instructionsClicked" class="instructions" @click = "aboutClicked = false, instructionsClicked = true" src="../Images/instructions_icon.png" alt="About"/> 
       <!-- <div class = "about" v-if = "!iconClicked" @click= "iconClicked = true">About</div> -->

      <!-- Go Back brings you back to Home Screen page-->
      <img v-if = "aboutClicked || instructionsClicked" class="goBack" @click = "aboutClicked = false, instructionsClicked = false" src="../Images/back.png" alt="Go Back" />
      <!-- <div class = "goBack" v-if = "iconClicked" @click= "iconClicked = false">Go Back</div> -->
          
      </div>
    </div>
 
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

.title {
  color: #e6e2d3;
  float: center;
  font-size: 70px;
  padding: 0px;
  text-align: center;
  font-family: Impact;
  margin-left: 2.5%
}

.about {
  margin-top: 1%;
  height: 50px;
  width: 50px;
  padding: 5px;
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

.navbar {
  background-color: #3e4444;
  width: 100%;
  height: 100px;  
  border: 4px solid #333333;
}

.goBack {
  margin-top: 1%;
  height: 60px;
  width: 60px;
  float: right;
  cursor: pointer;
}

</style>
