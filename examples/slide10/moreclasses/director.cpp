#include "director.h"


void Director::print() const{
	Manager::print();
	cout << "未知:" << unknown << endl;
}