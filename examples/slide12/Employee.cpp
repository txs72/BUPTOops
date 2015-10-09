#include <string.h>
#include <iostream>
#include <list>

using namespace std;

struct Employee
{
    string first_name;
    string family_name;
    char middle_initial;
    long hiring_date;
    short department;
};


struct Manager : public Employee
{
    list<Employee*> group;
    short level;
};

void g(Manager mm, Employee ee);
int main()
{
    Employee ee;
    ee.first_name = "tang";
    ee.family_name = "xs";
    ee.middle_initial = 'e';
    ee.hiring_date = 1111;
    ee.department = 1;
    Manager mm;
    mm.first_name = "xs";
    mm.family_name = "t";
    mm.middle_initial = 'f';
    mm.hiring_date = 2222;
    mm.department = 3;
    g(mm,ee);
    return 0;
}

void g(Manager mm, Employee ee)
{
    Employee* pe = &mm;
    Manager* pm = static_cast<Manager*>(&ee);
    pm->level = 2;
    pm=static_cast<Manager*>(pe);
    cout << pm->level << endl;
    pm->level = 2;
    cout << pm->level << endl;
}
