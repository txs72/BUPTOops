#include <string>
#include <iostream>

using namespace std;

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

class Employee{
    string name;
    short department;
public:
    Employee(const string& n, int d):name(n),department(d){}
    virtual void print() const; // 指明print()的作用就像是一个界面
	virtual ~Employee(){ cout << "Called Employee dtor." << endl;};
	// 可以在~Employee()析构函数前添加virtual关键字，看看输出情况有什么变化。
	// 如果Employee, Manager, Director均为Auto变量，那么virtual加与不加，没有什么区别
	// 但是，如果是使用Employee*生成多个指针，并让指针指向new出来的各种子类对象
	// 没有virtual关键字可能会导致某个派生类的析构函数不会被调用，这会导致很严重的资源未释放问题
	// 可以参照普通虚函数中virtual的作用来理解虚析构函数

	// 以下是一份网上的关于虚析构函数的解释，供参考

	// 构造函数不能用虚拟，因为用也没用，不管是在栈上构造对象，还是在堆上构造对象，
	// 也不管你以后是否使用父类的指针或引用来指向或引用这个对象，在构造的那“一瞬间”，
	// 总归要指明要构造对象的具体类型，所以，对象在构造过程中不存在运行时动态绑定的多态行为。
	// 你理解这个意思吗？举了例子就明白了，通常，假如A是B的父类，
	//	A* p = new B();
	// 则对于虚拟函数f，可以通过A类的指针p直接调用到B类的函数，这就是运行时的多态：
	//	p->f();
	// 但你注意没有，B类的对象却必须通过“A* p = new B();”来构造，显然不能通过“A* p = new A();”
	// 来构造一个B类对象——这是荒唐的，这只能构造一个A类的对象。所以构造函数虚拟无意义。
		
	// 但析构函数就不同了，p明明是个A类的指针，如果析构函数不是虚拟的，那么，
	// 你后面就必须这样才能安全的删除这个指针：
	//	delete (B*)p;
	// 但如果构造函数是虚拟的，就可以在运行时动态绑定到B类的析构函数，直接：
	//	delete p;
	// 就可以了。这就是虚析构函数的作用。而事实上，在运行时，你并不是总是能知道p所
	// 指对象的实际类型从而进行强制转换，所以，C++语言既然要支持多态，也就必须支持虚拟析构。
};

#endif // _EMPLOYEE_H
