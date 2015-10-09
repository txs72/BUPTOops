#include <iostream>
using namespace std;

#ifndef COMPLEX_H__
#define COMPLEX_H__
// 077 = 0111111 = 111111111000000 & i 
class complex
{
    double re, im;
public:
    complex(double r, double i) : re(r) , im(i) {}
    complex(double r) : re(r) , im(0) {}
    complex() : re(0) , im(0) {}

    complex(const complex& c){
        re = c.real();
        im = c.imag();
    }
    double real() const {return re;}
    double imag() const {return im;}
    complex& operator+=(complex);
    operator double() const { return re+im; }
};
bool operator==(complex, complex);
complex operator+(const complex,const complex);
complex operator+(double,const complex);
ostream& operator<<(ostream&, const complex);

#endif // COMPLEX_H__

