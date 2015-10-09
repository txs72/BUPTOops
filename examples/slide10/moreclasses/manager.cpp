#include "manager.h"

void Manager::print() const{
	Employee::print();
	cout << "级别:" << level << endl;
}