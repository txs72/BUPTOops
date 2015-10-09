#include "manager.h"
#include "employee.h"
#include "director.h"
#include "display.h"

int main(){

// 	Employee e("张三", 1);
// 	Manager m("李四", 2, 2);
// 	Director d("王五", 3, 3, 290);
// 	
// 	display_employee(&e);
// 	display_employee(&m);
// 	display_employee(&d);

	 
	Employee *e = new Employee("张三", 1);
	Employee *m = new Manager("李四", 2, 2);
	Employee *d = new Director("王五", 3, 3, 290);

	display_employee(e);
	display_employee(m);
	display_employee(d);

	delete e; 
	delete m;
	delete d;
	

	return 0;
}

