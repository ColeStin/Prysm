<!-- Name of Artifact: App.vue
    Summary: Sets up app with front, color, and merges components
    to all work together in final display.
    Programmer's Name(s): Gage Burmaster, Alex Wilhelm
    Date Code was Created: 9/15/2022 
    Date code was revised: 
     9/25 - Alexander Wilhelm - Prologue documentation
     10/20 - Alexander Wilhelm - Added AboutScreen switching
     12/4 - Alex - Refactoring of code
     12/6 - Alex - Completion of new updated Navbar
-->
<template>
<div class="navbar">
  <head>
    <meta charset="utf-8">
    <meta name = "viewport" content = "width=device-width, initial-scale = 1.0">
  </head>
  <body>
    <nav>
      <label class = "logo" > Prysm </label>
      <ul>
        <!-- Home Navigation System--> 
        <li><a v-if = "stayVisible" class = "pageSelector" @click = "aboutClicked = false, instructionsClicked = false"> Home </a></li>

        <!-- InstructionScreen Navigation System--> 
        <li><a v-if = "stayVisible" class = "pageSelector" @click = "aboutClicked = false, instructionsClicked = true"> Instructions </a></li> 

        <!-- AboutScreen Navigation System--> 
        <li><a v-if = "stayVisible" class = "pageSelector" @click = "aboutClicked = true, instructionsClicked = false"> About </a></li>
      </ul> 
    </nav>
  </body>  
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
    aboutClicked: false,
    stayVisible: true
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
background-image: url("../Images/aboutBackground2.png");
}

*{
 padding: 0;
 /* margin: 0; */
 text-decoration: none;
 list-style: none;
 box-sizing: border-box; 
} 

body
{
  font-family: montserrat;
}

nav {
  background: #2c3e50;
  height: 80px;
  width: 100.5%;
  border-radius: 5px;
}

nav ul {
  float: right;
  margin-right: 20px;
}

nav ul li {
  display: inline-block;
  line-height: 60px;
  margin: 0 5px;
}

nav ul li a 
{
  color: white;
  font-size: 17px;
  /* padding: 7px 13px; */
  border-radius: 3 px;
  text-transform: uppercase;
}

a:hover {
  background: #1b9bff;
  border-radius: 5px;
  transition: 1s;
}

label.logo 
{
  color: white;
  font-size: 35px;
  line-height: 80px;
  padding: 0 100px;
  margin-right: 59%;
  font-weight: bold;
}

.pageSelector
{
  cursor: pointer;
} 
@import url("https://unpkg.com/mathlive@0.27.4/dist/mathlive.css");
@import url("https://unpkg.com/mathlive@0.27.4/dist/mathlive.core.css");
</style>