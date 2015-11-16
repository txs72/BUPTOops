#include <iostream>
using namespace std;
extern int x;
int f();
void g(){
  x = f();
}

int main(){
  cout << "before g() called, x = " << x << endl;
  g();
  cout << "after g() called, x = " << x << endl;
  cout << "hello" << endl;
}
