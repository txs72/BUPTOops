#include <iostream>
using namespace std;

class Date{
 private:
    int d, m, y;
public:
    Date(const Date& dd){
      cout << "constructor" << endl;

      d = dd.d; 
      m = dd.m;       
      y=dd.y;
    }

    Date& operator=(const Date& dd){
      cout << "assignment" << endl;
        if(this != &dd) { // ·ÀÖ¹×Ô¸³Öµ
            d = dd.d; m = dd.m; y = dd.y;
        }
        return *this;
    }
    Date(int, int, int);
    int day() const {return d;}
    int month() const {return m;};
    int year() const {return y;};

    void test(Date dd){
        cout << dd.d;
    }
};
//cygwin gcc
Date::Date(int d, int m, int y)
{
     cout << "now is here" << endl;
    this->d = d;
    this->m = m;
    this->y = y;
}

int main(){
    Date d1(10,10,10);
    Date d2 = d1;
    Date d3(1,1,1);
    d3 = d1;
    //int i = d1.d;
    d3.test(d1);
    //cout << d1;
    //cout << d1;
}
