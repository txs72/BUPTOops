#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	// bool 部分
	cout << "bool 部分:" << endl;
	int a, b;
	bool b1;
	a = b = 10;
	b1 = a == b; 
	cout << "b1 = " << b1 << endl;

	bool b2 = 7;
	cout << "b2 = " << b2 << endl;

	bool b3 = true;
	cout << "b3 = " << b3 << endl;
	cout << endl;

	// char 部分
	cout << "char 部分:" << endl;
	char v1[] = "a\xah\129";
	char v2[] = "a\xah\127";
	char v3[] = "a\xad\127";
	char v4[] = "a\xad\0127";

	cout << "v1's length is " << strlen(v1) << endl;
	cout << "v2's length is " << strlen(v2) << endl;
	cout << "v3's length is " << strlen(v3) << endl;
	cout << "v4's length is " << strlen(v4) << endl;

	unsigned char c = 255;
	int i = c;
	cout << "i = " << i << endl;
	
	// numeric_limits
	cout << "largest float == " << numeric_limits <float> :: max() 
		<< ", char is signed == " << numeric_limits<char> :: is_signed << endl;

	// Enum part
	enum flag {x = 1, y = 2, z = 4, e = 8};
	flag f1 = flag(5);
	flag f4 = flag(99);
	
	cout << f4;
	return 0;
}
