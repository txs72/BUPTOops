#include <iostream>
using namespace std;

void f1(int a)
{
  while(a--){
    static int n = 0; // 初始化仅一次
    int x = 0; // 每次循环都初始化
    cout << "n=" << n++ << " , x=" << x << endl;
  }
}

void f2(int val, int& ref){
  val ++; 
  ref ++;
}

void error(string s) {
  cout << s << endl;
}

typedef void (*PF)();

void cut() { cout << "called cut func..." << endl;}
void paste() { cout << "called paste func..." << endl;}
void copy() { cout << "called copy func..." << endl;}
void search() { cout << "called search func..." << endl;}

int main(){  
  f1(3); // 静态变量示例

  int i=1,j=1;
  f2(i,j); // 引用方式传参，可以使得被调用函数修改本地局部变量的值
  cout << "i=" << i << " , j=" << j << endl;

  void (*efct)(string); // 定义函数指针efct
  efct = &error; // 或者efct = error
  (*efct)("error msg"); // 或者efct("error msg");

  PF edit_ops[] = {&cut, &paste, &copy, &search};
  PF* button = edit_ops;
  button[2](); // 调用copy函数

  return 0;
}

