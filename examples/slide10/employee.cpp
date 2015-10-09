#include <iostream>
#include <list>
using namespace std;

class Employee{
    string first_name, family_name;
    short department;
public:
    Employee(const string& n, int d):family_name(n),department(d){};
    //Employee(){};
    void print() const; // 指明print()的作用就像是一个界面
};

void Employee::print() const{
  cout << "----------" << endl << "Now in Base class: " << family_name << department << endl;
  cout << "----------" << endl; 
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
    cout << "--------------------" << "now in Derived class: " << level << endl;
    cout << "--------------------" << endl;
}
void print_list(const list<Employee*>& s)
{  
for(list<Employee*>:: const_iterator p=s.begin(); p!=s.end(); ++p) 
    (*p)->print();
} // Dynamic Binding virtual overriding // Static Binding overloading

int main(){
    Employee e("Brown",123);
    Manager m("Smith",456,2);
    list<Employee*> empl;
    empl.push_front(&e);
    empl.push_front(&m);
    print_list(empl);
}
