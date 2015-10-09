#include <iostream>
#include <vector>
#include "complex.h"

using namespace std;

class Add{
  complex val;
public:
  Add(complex c) {val = c;}
  Add(double r, double i) { val = complex(r,i); }
  void operator()(complex& c) const { c += val; }
};

int main()
{
  vector<complex> vi;

  for(int i=1; i<10; i++) vi.push_back(i);

  for_each(vi.begin(), vi.end(), Add(2,3));

  for(vector<complex>::iterator p = vi.begin(); p!= vi.end(); ++p)
  {
    cout << *p << endl;
  }
}
