#include "complex.h"
#include <iostream>
using namespace std;
// implementation of operator +=
complex& complex::operator+=(complex a){
    this->re += a.re;
    this->im += a.im;
    return *this;	
}


bool operator==(complex z1, complex z2){
    return z1.real() == z2.real() && z1.imag() == z2.imag();
}

// operator +
complex operator+(complex z1, complex z2){
    double re, im;
    re = z1.real() + z2.real();
    im = z1.imag() + z2.imag();
    return complex(re,im);
}
// operator +
complex operator+(double d, complex z2){
    double re, im;
    re = d+ z2.real();
    im = z2.imag();
    return complex(re,im);
}

// operator <<
ostream& operator<<(ostream& cout, const complex z){
    cout << z.real();
    cout << "+" << z.imag() << "i" << endl;
    return cout;
}
