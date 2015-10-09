#include <iostream>

using std::cout;
using std::endl;

class Student
{
	int grade;
public:
	static int count;
	Student(){Student::count++;}
};

int Student::count = 0;

int main(){
	//int studentCount = 0;
	Student s1; 
	Student s2; 
	Student s3; 
	cout << s1.count << endl;
	cout << Student::count << endl;
}

