import { createApp } from 'vue'
import App from './App.vue'
import VueKonva from 'vue-konva';
const app = createApp(App);
app.use(VueKonva);
//Vue.use(paper);
app.mount('#app');
