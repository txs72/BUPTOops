#include <iostream>
#include <complex>
#include <vector>
#include <list>

using namespace std;
//typedef complex<double> MyComplex;
class Add{
    complex<double> val;
public:
    Add(complex<double> c) { val=c; }
    Add(double r, double i){ val = complex<double>(r,i); }
    void operator()(complex<double>& c) const{ c+= val; }
};

template<class Iter, class Fct>Fct for_each1
    (Iter b, Iter e, Fct f)
{
    while(b!=e) f(*b++); // f Add(2,3) (*b )
    return f;
};

// for_each是一个模板，它反复地应用第三个参数的()
void negate1(complex<double>& c){ c = -c; }


int main()
{
    complex<double> c1(1,1);
    complex<double> c2(2,2);
    complex<double> c3(3,3);
    vector<complex<double> > aa;
    aa.push_back(c1);
    aa.push_back(c2);
    aa.push_back(c3);

    list<complex<double> > ll;
    ll.push_back(c1);
    ll.push_back(c2);
    ll.push_back(c3);
    for_each1(aa.begin(), aa.end(), Add(2,3));
    for_each1(ll.begin(), ll.end(), negate1);

    for(vector<complex<double> >::iterator p = aa.begin();
        p!=aa.end(); ++p){
        cout << *p << endl;
    }
    for(list<complex<double> >::iterator p = ll.begin();
        p!=ll.end(); ++p){
        cout << *p << endl;
    }
    return 0;
}
