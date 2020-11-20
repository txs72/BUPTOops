gcc系列编译器不支持export关键字，可考虑使用extern替代

支持export的编译器有

Comeau on Unix， 使用--export, -A or --strict
Comeau on Windows， 使用 --export or -A
Intel on Linux，使用--export or --strict-ansi

关于指定template实现目录
comeau --template_directory=<path>
intel  --export_dir<path>

命令行示例

1. como -c --export plus.cpp
生成plus.et用以描述实现在plus.cpp中的template

2. como -c --export test.cpp
生成test.o

3. como --export -o test test.o
生成可执行文件

2.3.两步也可以合并为一个
como --export -o test test.cpp

此外，假设plus.h和plus.cpp放置于plus目录，test.cpp放置于其子目录，可以如下操作
como --export --template_directory=../plus -I../plus -o test test.cpp

总结，c++支持两种函数模板以及类模板模型，一种是inclusion模型，另一种是separation模型, inclusion模型是我们所熟识的，但可能有点反常识，毕竟，模板声明和定义会通过头文件，被包含在所有源代码中，separation模型跟我们平时的函数使用方式类似，但export关键字已经被废弃不用


以下资料来自链接

https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s27.html

The separation model offers several potential benefits:

Reduced compilation times
Compilation time may improve with the separation model because a template’s definition needs to be scanned less frequently and because the separation modules reduce dependencies between modules.

Reduced symbolic “pollution”
Names of functions, classes, and data used in a template’s implementation file can be completely hidden from code that uses the template, reducing the possibility of accidental name clashes. In addition, the author of a template implementation can worry less about accidental clashes with names from the source files that use the template.

The ability to ship precompiled template implementations
In theory, under the separation mode, a vendor could ship template implementations that have been precompiled into a binary format somewhere between C++ source code and ordinary object files.

All three potential advantages of the separation model are controversial. First, while some users have reported reduced compile times, the separation model can also lead to longer compile times in some cases. At the moment, there is insufficient data to make a definitive judgment. Second, while the separation model does reduce some forms of symbolic pollution, the language rules necessary to support the separation model, particularly the notion of two-phase lookup , have complicated the way templated code is written—even when using the inclusion model—and have had some unintended consequences. Third, all existing implementations of the separation model are based on the EDG frontend, and EDG has not yet provided any means to compile source files containing exported template implementations into binary files that can be shipped in lieu of the source.

There was an effort in 2003 to remove exported templates from future versions of the C++ standard, but it failed. Consequently, exported templates are a permanent part of the C++ language, and you should learn to use them.

