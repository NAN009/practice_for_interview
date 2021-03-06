//中缀表达式向后缀表达式转换：
//设置两个栈来实现，stack站用来存放运算符，post栈用来存放最后的后缀表达式。
//转换原则是：从左到右扫描中缀表达式，若读到操作数，则存入post栈，若读到运算符：
//1、该运算符是"("，则直接存入stack栈。
//2、该运算符是")",则将stack栈中第一个"("前所有运算符依次出栈，并依次存入post栈，但"("、")"都不存入post栈；
//3、若该运算符为非括号，则将该运算符和stack栈定运算符做比较：若高于等于栈顶运算发，在直接存入stack栈，否则将栈顶运算符出栈，存入post栈。当扫描完成后，stack栈中还有运算符时，将左右运算符出栈，存入post栈。

//先将中缀表达式用二叉树表示，在后序遍历该二叉树，得到后缀表达式。
//后缀表达式求值：顺序扫描表达式的每一项，然后根据它的类型做如下操作：若是操作数，则将其压入栈中，若是操作符<op>，则连续从栈中退出两个操作数Y和X，形成运算指令X<op>Y,并将计算结果重新压入栈中，当表达式的所有想都扫描并处理后，栈顶存放的就是最后计算结果。