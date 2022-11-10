<!-- Name of Artifact: App.vue
    Summary: Sets up app with front, color, and merges components
    to all work together in final display.
    Programmer's Name(s): Gage Burmaster, Alex Wilhelm
    Date Code was Created: 9/15/2022 
    Date code was revised: 
     9/25 - Alexander Wilhelm - Prologue documentation
     10/20 - Alexander Wilhelm - Added AboutScreen switching
-->
<template>
    <div class="navbar">
      <div class="title"> 
        Prysm
      <!-- Info image which will link to about page which credits to all makers of the project-->
      <img v-if = "!iconClicked" class="info" @click = "iconClicked = true" src="../public/info_icon.png" alt="About" />  

      <!-- Go Back brings you back to Home Screen page-->
      <img v-if = "iconClicked" class="goBack" @click = "iconClicked = false" src="../public/back.png" alt="Go Back" />
      <!-- <div class = "goBack" v-if = "iconClicked" @click= "iconClicked = false">Go Back</div> -->
      

      </div>

     

    
 
    </div>
 
  <HomeScreen v-if = "!iconClicked"></HomeScreen> 
  <AboutScreen v-if = "iconClicked"></AboutScreen>

</template>

<script>

import HomeScreen from './components/HomeScreen.vue'
import AboutScreen from './components/AboutScreen.vue'

export default {
  
  data: function () {
    return {
      iconClicked: false
    };
  },
  name: 'App',
  components: {
    HomeScreen, AboutScreen

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
  padding: 25px;
  text-align: center;
  font-family: Impact;
  margin-left: 2.5%
}

.info {
  margin-top: 1%;
  height: 60px;
  width: 60px;
  float: right;
}

.about {
  color: #e6e2d3;
  font-family: Impact;
}

.navbar {
  background-color: #3e4444;
  width: 100%;
  height: 150px;
  padding: 0px;
}
.goBack {
  margin-top: 1%;
  height: 60px;
  width: 60px;
  float: right;
}
</style>
