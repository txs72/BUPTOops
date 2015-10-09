#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "Date.h"

using namespace std;

Date Date::default_date(1,10,1949); // 建国

Date::Date(int d, int m, int y){
	cache_valid =  false;
	cache = "";
	this->d = d? d : default_date.d;
	this->m = m? m : default_date.m;
	this->y = y? y : default_date.y;
}


Date::Date(const Date & date){
	cout << "Now in copy ctor\n";
	d = date.d;
	m = date.m;
	y = date.y;
}

void Date::set_default(int d, int m, int y)
{
    Date::default_date = Date(d,m,y);
}
//Date()相当于Date::default_date

int Date::getD() const{ return d;}
int Date::getM() const{ return m;}
int Date::getY() const{ return y;}
void Date::setD(int d){this->d = d;}
void Date::setM(int m){this->m = m;}
void Date::setY(int y){this->y = y;}

Date& Date::add_year(int n)
{
//    if(d==29 && m==2 && !leapyear(y+n)){
//        d = 1;
//        m = 3;
//    }
    y+=n;
    return *this;
}

Date& Date::add_month(int n) // 假定 n小于12
{
    if(this->m + n > 12) {
		this->m = (this->m + n) % 12;
		y += 1;
	}
	else this->m += n;
    return *this;
}

Date& Date::add_day(int n) // 假定 n小于30
{
    if(this->d + n > 31) {
		this->d = (this->d + n) % 31;
		m += 1;
	}
	else this->d += n;
    return *this;
}

void Date::print(){
	cout << "Year: " << y << " ";
	cout << "Month: " << m << " ";
	cout << "Day: " << d << endl;
}

string Date::string_rep() const
{
    if(cache_valid == false){
        Date* th = const_cast<Date*>(this);
        th->compute_cache_value();
        th->cache_valid = true;
    }
    return cache;

	/*
    if(cache_valid == false){
        compute_cache_value();
        cache_valid = true;
    }
    return cache;
	*/
}

void Date::compute_cache_value(){
	char s[10];
	sprintf(s, "%d", y);
	cache = "Year: ";
	cache += s;
	sprintf(s, "%d", m);
	cache += " and Month: ";
	cache += s;
	sprintf(s, "%d", d);
	cache += " and Day: ";
	cache += s;
}
