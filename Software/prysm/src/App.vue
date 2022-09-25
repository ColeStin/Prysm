<template>
<HomeScreen></HomeScreen>
</template>

<script>
// import HelloWorld from './components/HelloWorld.vue'
import HomeScreen from './components/HomeScreen.vue'
export default {
  name: 'App',
  components: {
    HomeScreen,
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
