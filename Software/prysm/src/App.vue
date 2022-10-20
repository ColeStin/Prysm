<!-- Name of Artifact: App.vue
    Summary: Sets up app with front, color, and merges components
    to all work together in final display.
    Programmer's Name(s): Gage Burmaster
    Date Code was Created: 9/15/2022 
    Date code was revised: 
     9/25 - Alexander Wilhelm - Prologue documentation
-->
<template>
<HomeScreen></HomeScreen>
<AboutScreen></AboutScreen>
</template>

<script>
// import HelloWorld from './components/HelloWorld.vue'
import HomeScreen from './components/HomeScreen.vue'
import AboutScreen from './components/AboutScreen.vue'
export default {
  name: 'App',
  components: {
    HomeScreen, AboutScreen

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
</style>
