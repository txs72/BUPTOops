#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void f(int);

class Name{ const char* s; };
class Table{
    Name* p;
    size_t sz;
    double r;    
public:
    Table(size_t s = 15) {
      srand(time(NULL));
      r = random(); 
      cout << "r=" << r << "\t" << "in ctor" << endl;
      p = new Name[sz=s]; 
    }
    ~Table() { 
      cout << "r=" << r << "\t" << "in dtor" << endl;
      delete []p; 
    }
    Name* lookup(const char*);
    bool insert(Name*);
};

int main(){
  f(1); 
  return 0;
}

void f(int i)
{
  Table aa;
  Table bb;
  if(i>0) {
    Table cc;
  }
  Table dd;
}
