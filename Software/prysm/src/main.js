import { createApp } from 'vue'
import App from './App.vue'
import VueKonva from 'vue-konva';
const app = createApp(App);
app.use(VueKonva); //imports the konva module to our vue instance 
//Vue.use(paper);
app.mount('#app');
