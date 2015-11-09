#include <iostream>

using namespace std;

int main()
{
    const char * str1 = "This is constant string";
    const char * str2 = "This is constant string";
    const char str3[] = "This is constant string";
    const char str4[] = "This is constant string";
    char * str5 = "This is constant string";

    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str1 == str5) << endl;
  //str5[1] = 'a';          //exception
    //str5 = (char *)0x1021 ; //normal
    //str1 = (char *)0x1021 ; //normal
    //char alpha[] = "abcdefghijklmn"
    //"opqrstuvwxyz";
    //cout << alpha << endl;

    char str[] = "Jers\000Munk";
    cout << str << endl;
    cout << "str's length is: " << strlen(str) << endl;
    cout << "\t and the real space it occupies is: " << sizeof(str) << endl;

}

