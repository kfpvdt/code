var first_keywords = {};

        //定义每个字母对应的第二个下拉框
        first_keywords['A'] = ['a1', 'a2', 'a3'];
        first_keywords['B'] = ['b1', 'b2', 'b3'];
        first_keywords['C'] = ['c1', 'c2', 'c3'];

        function Change_second_selectwords() {
            //根据id找到两个下拉框对象
            var target1 = document.getElementById("initials");
            var target2 = document.getElementById("top_domains");
            //得到第一个下拉框的内容
            var selected_initial = target1.options[target1.selectedIndex].value;

            //清空第二个下拉框
            while (target2.options.length) {
                target2.remove(0);
            }
        //根据第一个下拉框的内容找到对应的列表
        var initial_list = first_keywords[selected_initial];
        if (initial_list) {
            for (var i = 0; i < initial_list.length; i++) {
                var item = new Option(initial_list[i], i);
                //将列表中的内容加入到第二个下拉框
                target2.options.add(item);
            }
        }
} 