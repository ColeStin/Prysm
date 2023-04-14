import { createApp } from 'vue'
import App from './App.vue'
import VueMathjax from 'vue-mathjax-next'
const app = createApp(App);
app.use(VueMathjax);
//Vue.use(paper);
app.mount('#app');
