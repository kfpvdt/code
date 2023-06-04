new Vue({
    el:"#app",
    data:{
        isShow:false,
        message:'显示'
         },
    methods:{
      click(){
         this.isShow = !this.isShow;
         if(this.isShow){
             this.message='隐藏';
            }else{
             this.message='显示';
            }
          }
        }
     })