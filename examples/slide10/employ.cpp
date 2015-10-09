#include <iostream>
#include <string>
#include <list>
using namespace std;

class Employee{
    string first_name, family_name;
    short department;
public:
    Employee(const string& n, int d):first_name(n),department(d){};
    virtual void print() const; // 指明print()的作用就像是一个界面
};

void Employee::print() const{
    cout << first_name << endl << department << endl;
}

class Manager:public Employee {
    list<Employee*> group;
    short level;
public:
    Manager(const string& n, int d, int lvl):Employee(n,d),level(lvl){};
    void print() const;
};

void Manager::print() const {
    Employee::print();
    cout << level << endl;
}

void print_list(const list<Employee*>& s)
{  
    for(list<Employee*>:: const_iterator p=s.begin(); p!=s.end(); ++p) 
        (*p)->print();
}

int main(){
    Employee e("Brown",1234);
    Manager m("Smith",1234,2);
    list <Employee*> empl;
    empl.push_front(&e);
    empl.push_front(&m);
    print_list(empl);
}
