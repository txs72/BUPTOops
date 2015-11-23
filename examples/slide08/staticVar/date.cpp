#include <iostream>
#include "date.h"

using namespace std;

Date Date::default_date(11,11,2011);
int Date::count = 0;

void Date::init_date(int dd, int mm, int yy){
  d = dd;
  m = mm;
  y = yy;
} 

void Date::add_year(int n){
  y = y + n;
}

void Date::add_month(int n){
  m = m + n;
}

void Date::add_day(int n){
  d = d + n;
}

void Date::print(){
  cout << "year=" << y << endl;
  cout << "month=" << m << endl;
  cout << "day=" << d << endl;
}

