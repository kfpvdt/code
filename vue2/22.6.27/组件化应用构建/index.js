src="../组件化应用构建/index.html"

Vue.component('todo-item', {
    // todo-item 组件现在接受一个
    // "prop"，类似于一个自定义 attribute。
    // 这个 prop 名为 todo。
    props: ['todo'],
    template: '<li>{{ todo.text }}</li>'
  })
  Vue.component('todo-item', {
    props: ['todo'],
    template: '<li>{{ todo.text }}</li>'
  })
  
  var app7 = new Vue({
    el: '#app-7',
    data: {
      groceryList: [
        { id: 0, text: '蔬菜' },
        { id: 1, text: '奶酪' },
        { id: 2, text: '随便其它什么人吃的东西' }
      ]
    }
  })