#include <iostream>
#include "add.h"

using namespace std;

extern int e;


int main()
{
  int a, b, c;
  a = 10;
  b = 20;
  c = add(a, e);
  cout << "c=" << c << endl;
  cout << "Hello, world!" << endl;
  return 0;
}

