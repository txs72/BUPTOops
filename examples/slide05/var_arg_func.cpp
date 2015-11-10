//#include "stdio.h" 
//#include "stdarg.h" 
#include <iostream>
#include <cstdarg>

using namespace std;

void va_fun(int start, ...) 
{ 
  va_list arg_ptr; 
  int value =start; 
  int index=0; //可变参数下标 
  va_start(arg_ptr,start); //以固定参数的地址为起点确定变参的内存起始地址。 
  cout << "Argument list: ";
  do 
  { 
    ++index; 
    cout << index << "=>" << value << " "; //输出各参数的值 
    value = va_arg(arg_ptr,int); //得到下一个可变参数的值 
  } while(value != -1); 
  cout << endl;
  return; 
} 
int main(int argc, char* argv[]) 
{ 
  va_fun(10,-1); 
  va_fun(10,20,-1); 
  va_fun(10,20,30,40,50,60,70,80,90,-1); 
  return 0; 
} 
