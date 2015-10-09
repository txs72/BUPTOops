第一个示例中，add函数被编译两遍，分别存储于source1.o和source2.o中，链接时抛弃一份。

第二个示例中，source2.cpp显式使用extern template
1、说明欲使用的add函数为已经在其他源文件中声明的模板函数
2、在本文件中的使用方式为，用int类型将其实例化，而这种方式已经被使用过

extern template的使用效果，使得source2.o中没有add函数的编译结果（可使用nm命令对比source1.o的大小查看），减少编译时间。


