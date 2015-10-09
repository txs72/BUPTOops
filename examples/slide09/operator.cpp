#include <iostream>
using namespace std;
class complex {
    double re, im;
public:
    complex(double r, double i) : re(r), im(i) {}
    complex operator+(complex);
    complex operator*(complex);
    double getRe() const{ return re;}
    double getIm() const{ return im;}
};

void print(complex c);

complex complex::operator+(complex c){
    return complex(re + c.re , im + c.im);
}

complex complex::operator*(complex c){
    return complex(re*c.re - im*c.im, re*c.im + im*c.re);
}

complex operator+(int i, complex c){
    return complex(i+c.getRe(), c.getIm());
}

int main() {
    complex a = complex(1,3);
    complex b = complex(1,2);
    complex c = b; // 复制构造函数
    complex d(1,1);
    complex e = 1 + d;
    a = b+c; // a = b.operator+(c)
    b = b+c*a; // 运算符优先级仍然有效 b = b.operator+(c.operator*(a))
    c = a*complex(1,2);
    print(a);print(b);print(c);
    //cout << a << b << c;
	return 0;
}

void print(complex c){
    cout << "当前数值为：" << c.getRe() << "+" << c.getIm() << "i" << endl;
}
