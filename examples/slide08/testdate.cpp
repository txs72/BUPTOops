#include <iostream>
#include "Date.h"

using namespace std;

// 完成Date类的测试
int main(int argc, char** argv)
{
	// 测试默认构造函数
	Date dd;
	cout << "Date dd;" << endl;
	dd.print();
	cout << endl;
	// 测试普通构造函数
	Date today(6,11,2006);
	cout << "Date today(6,11,2006);" << endl;
	today.print();
	cout << endl;

	// 测试复制构造函数
	Date d = today; 
	cout << "Date d = today; " << endl;
	d.print();
	cout << endl;

	// 测试赋值复制函数
	Date d1;
	d1 = today; 
	cout << "Date d1;" << endl;
	cout << "d1 = today; " << endl;
	d1.print();
	//cout << d.getD();

	cout << "default_date is : ";
	Date::default_date.print();
	
	// 测试修改日期
	cout << "today is 2006.11.6" << endl;;
	today.add_year(1).add_month(1).add_day(10);
	cout << "today.add_year(1).add_month(1).add_day(10);" << endl;
	today.print();

	cout << endl;
	// 测试逻辑的常量性问题
	cout << "Now printing string representation of today: ";
	cout << today.string_rep() << endl;

	const Date d2; // 应该是default_date
	cout << "const Date d2;" << endl;
	cout << d2.string_rep() << endl;


}
