import { createApp } from "vue";
import "./styles.css";
import App from "./App.vue";
import router from "./router";
import groupList from "./data";
import 'highlight.js/styles/stackoverflow-light.css'
import 'highlight.js/lib/common';
import hljsVuePlugin from "@highlightjs/vue-plugin";

createApp(App)
    .use(router)
    .use(hljsVuePlugin)
    .mount("#app");