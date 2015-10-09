#include "employee.h"

#ifndef _MANAGER_H
#define _MANAGER_H

class Manager: public Employee{
	short level;
public:
	Manager(const string& n, int d, short lvl):Employee(n,d), level(lvl){}
	void print() const;
	~Manager(){ cout << "Called Manager dtor." << endl;}
};

#endif // _MANAGER_H