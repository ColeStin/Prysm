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
    
    <div class="title">
      <!-- Info image which will link to about page which credits to all makers of the project-->
     <img v-if = "!iconClicked" class="info" @click = "iconClicked = true" src="../public/info_icon.png" alt="About" />
      <div class="navbar">
      Prysm
    </div>
      <!-- Go Back brings you back to Home Screen page-->
    <div class = "goBack" v-if = "iconClicked" @click= "iconClicked = false">Go Back</div>
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
  methods: {
  }

}
</script>
  
<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
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

.info {
  height: 40px;
  width: 40px;
  margin-top: 12px;
  float: right;
}

.about {
  padding-left: 90%;
  margin-top: -33px;
  color: #e6e2d3;
  font-family: Impact;
}

.navbar {
  background-color: #3e4444;
  width: 100%;
  height: 65px;
  padding: 0px;
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
