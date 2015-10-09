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
    Table(const Table&);
    Table& operator= (const Table&);
};

Table::Table(const Table& t){
  cout << "In Copy Ctor..." << endl;
  r = t.r;
  p = new Name[sz=t.sz];
  for(int i=0; i<sz; i++)
    p[i] = t.p[i];
}

Table& Table::operator= (const Table& t)
{
  cout << "Now in operator = func..." << endl;
  if(this!=&t)
  {
    delete []p;
    p = new Name[sz=t.sz];
    r = t.r;
    for(int i=0; i<sz; i++)
      p[i] = t.p[i];
  }
  return *this;
}


int main(){
  Table t1;
  Table t2 = t1;
  Table t3;
  t3 = t2;
  return 0;
}

