#include "complex.h"
#include <iostream>

using namespace std;

int main()
{
//    complex z = complex(1,2);
    complex z1(1,2);
    complex z2(1,2);
    complex z3 = z1 + z2;
    complex z4 = z1;
    double d1 = 1;
    bool b = z1 ==z2;
    //b = z1==d1;
    double d2 = z1;
    cout << d2 << endl;
    // cout << b;
	cout << z3;
    return 0;
}
