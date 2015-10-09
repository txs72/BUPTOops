//
//  main.cpp
//  HelloWorld
//
//  Created by young on 12-10-29.
//  Copyright (c) 2012年 young. All rights reserved.
//

#include <iostream>
using namespace std;

extern int x;
void f1();
void f2();

int main(int argc, const char * argv[])
{
    cout << x << endl;
    f1();
    f2();
    
    int a[] = {10,20,30};
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

