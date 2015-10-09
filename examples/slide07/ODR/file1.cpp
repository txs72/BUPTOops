//
//  file1.cpp
//  HelloWorld
//
//  Created by young on 12-10-29.
//  Copyright (c) 2012年 young. All rights reserved.
//
#include <iostream>

#define Point int

#include "file1.h"
#include "s.h"

using namespace std;

int x = 1;
s s1;

void f1()
{
    s1.a = 10;
    s1.b = 'b';
    
    
    cout << "Now in file1 f1()..." << endl;
    cout << "s.a = " << s1.a << endl;
    cout << "s.b = " << s1.a << endl;

}