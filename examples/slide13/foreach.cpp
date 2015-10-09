#include <iostream>
#include <complex>
#include <vector>
#include <list>

using namespace std;

void negate1(complex<double>& c){ c = -c;};

void add23(complex<double>& c)
{
    c+=complex<double>(2,3);
}

template<class Iter, class Fct>Fct for_each1(Iter b, Iter e, Fct f)
{
    while(b!=e) f(*b++);
    return f;
};

class Add{
    complex<double> val;
public:
    Add(complex<double> c) { val=c; }
    Add(double r, double i){ val = complex<double>(r,i); }
    void operator()(complex<double>& c) const{ c+= val; }
};


int main()
{
    complex<double> value(5.0,5.0);
    vector<complex<double> > aa;
    list<complex<double> > ll;

    aa.push_back(complex<double>(1,1));
    aa.push_back(complex<double>(2,2));

    ll.push_back(complex<double>(1,1));
    ll.push_back(complex<double>(2,2));

    for_each1(aa.begin(), aa.end(), Add(3,3));
    for_each1(ll.begin(), ll.end(), Add(value));

    for(vector<complex<double> >::const_iterator p = aa.begin(); p!=aa.end(); p++){
        cout << *p << endl;
    }

    for(list<complex<double> >::const_iterator p = ll.begin(); p!=ll.end(); p++){
        cout << *p << endl;
    }

    return 0;
}
