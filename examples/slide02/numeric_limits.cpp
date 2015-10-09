#include <limits>
#include <iostream>
using namespace std;
int main()
{
    cout << "largest double == " << 
    numeric_limits <double> :: max()
    << ", char is signed == " << 
    numeric_limits<char> :: is_signed 
    << endl;
}

