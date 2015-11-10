#include <stdio.h>
#include <iostream>
using namespace std;

// 可变参数宏，C99编译器起开始支持
#define OUTPUT(...) printf(__VA_ARGS__)

// 打开DEBUG模式，若不需要，将下面这行注释掉即可
#define DEBUG

// 一种调试输出代码的控制技术
#ifdef DEBUG
#define dbgprint(format, args...) fprintf(stderr, format, ##args)
#else
#define dbgprint(format, args...)
#endif

int main(){ 
  int x = 50;
  int y = 100;
  OUTPUT("y = %d\n", y);

  dbgprint("filename is: %s\n", __FILE__);
  dbgprint("x = %d, y = %d\n", x, y);
  return 0;
}

