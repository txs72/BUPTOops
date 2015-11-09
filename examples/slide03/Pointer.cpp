#include <iostream>
#include <string>

using namespace std;

int main()
{
    char c = 'a';
    char* p1 = &c;
    cout << "c\'s address is: " << &p1 << endl;
    cout << "p1's value is: " << *p1 << endl;
    cout << "the size of p is: " << sizeof(p1) << endl;
    cout << endl;

    cout << "sizeof 与 strlen的区别" << endl;
    cout << "----------------------" << endl;
    cout << "sizeof string \"test\" is: " << sizeof("test") << endl;
    cout << "string length of \"test\" is: " << strlen("test") << endl;

    // 一个常见错误
    char* p2 = "Plato";
    //p2[3] = 'e';

    // 常量字符串的处理
    const char* pp = "Heraclitus";
    const char* qq = "Heraclitus";

    if(pp==qq) cout << "One!" << endl;
    
    // 多行字符串
    char str3[] = "This is a two lines \n string..."; 
    char str1[] = "abcdefghijklmn"
            "opqrstuvwxyz"; 
    cout << str1 << endl;
    cout << str3 << endl;
    
    // 含有0字符的字符串
    char str2[] = "Jers\000Munk";
    cout << str2 << endl;
    cout << strlen(str2) << endl;
    cout << sizeof(str2) << endl;

    // 数组中元素的大小，通过地址来查看
    int vi[10];
    short vs[10];
    cout << &vi[0] << ' ' << &vi[1] << endl;
    cout << &vs[0] << ' ' << &vs[1] << endl;

    {
        // 指针运算
        int v1[10];
        int v2[10];
    
        int i1 = &v1[5] - &v1[3]; // i1 = 2
        int i2 = &v1[5] - &v2[3]; //结果无定义

        cout << i1 << endl;
        cout << i2 << endl;
    
        int* p1 = v2 + 2;  // p1= &v2[2]
        int* p2 = v2 - 2;  // p2无定义

        cout << p1 << endl;
        cout << p2 << endl;
    }
    
    {
        // 结构体示例
        struct address {
            char* name;
            long int number; // 4 bytes
            char* street;
            char* town;
            char state[2];
            long zip;
        }; //很多机器上，sizeof(address)是24
        cout << "struct size is: " << sizeof(struct address) << endl;

        address jd = { "Jim Dandy", 61, "South St", "New Providence", 
            {'N', 'J'}, 7974};
        cout << "name: \t" << jd.name << endl;
        cout << "number: \t" << jd.number << endl;
        cout << "street: \t" << jd.street << endl;
        cout << "town: \t" << jd.town << endl;
        cout << "state: \t" << jd.state[0] << "." << jd.state[1] << endl;
        cout << "zip: \t" << jd.zip << endl;

    }

    {
        const int x = 10;
        //x = 10;
    }

    {
        char c1 = 'a';
        char c2 = 'b';
        const char* p = &c1;
        // *p = 'c';
        p = &c2;
        // *p = 'c';
        char* const p2 = &c1;
        *p2 = 'c';
    }
    {
        void* pi;
        double* pd = static_cast<double*>(pi);
    }
    return 0;
}
