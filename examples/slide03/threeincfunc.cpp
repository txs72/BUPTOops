#include <iostream>

using namespace std;

void inc1(int);
void inc2(int*);
void inc3(int&);

int main()
{
	int a = 10;
    cout << "original number: " << a << endl << endl;

    inc1(a);
    cout << "after inc1 called: " << a << endl << endl;
	
    int* p = &a;
	inc2(p); // *p1
	cout << "after inc2 called: " << a << endl << endl;
    
    int& r = a;
    inc3(r);
    // inc3(a);
    cout << "after inc3 called: " << a << endl << endl;

	return 0;
}

void inc1(int a){
  a = a + 1;
}

void inc2(int* p2){
	// *p2
	*p2 = *p2 + 1;
}

void inc3(int& r){
  r = r + 1;
}

