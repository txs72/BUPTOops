#include "header.h"

extern template int add<int>(int, int);

void something2()
{
  int a=10, b=10;
  int c = add(a,b);
  cout << c << endl;
}


