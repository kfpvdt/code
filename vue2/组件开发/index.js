// 导入组件
import ButtonCounter from './component/ButtonCounter.vue';

// 注册组件
Vue.component('button-counter', ButtonCounter);

var app = new Vue({
        el:'#app',
        data:{
            message:'hello,world',
        },
        methods: {

            }
    })