#include <iostream>
#include "date.h"

using namespace std;

int main(){
	Date d1;
    Date d2; // 变量 对象
    for(int i = 0; i < 100; i ++){
      Date d;
    }
	//d1.add_year(4);
	//d1.add_day(12);
	
	//d1.y = 2019;
	
	d1.print();
	cout << "Total date objs = " << Date::count << endl;
	return 0;
}

