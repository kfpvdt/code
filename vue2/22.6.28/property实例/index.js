var app5 = new Vue({
    el: '#app-5',
    data: {
      message: 'Hello Vue.js!'
    },
    methods: {
      reverseMessage: function () {
        this.message = this.message.split('').reverse().join('')
        //split分割字符串 reverse反转   join将所有元素转换成字符串
      }
    }
  })