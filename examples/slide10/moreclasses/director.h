#include "manager.h"
#include "employee.h"

#ifndef _DIRECTOR_H
#define _DIRECTOR_H

class Director: public Manager{
	int unknown;

public:
	Director(const string& n, int d, short lvl, int uk):Manager(n,d,lvl), unknown(uk){}
	void print() const;
	~Director(){cout << "Called Director dtor." << endl;}
};

#endif // _DIRECTOR_H