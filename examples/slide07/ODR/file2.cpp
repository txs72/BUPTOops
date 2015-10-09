//
//  file2.cpp
//  HelloWorld
//
//  Created by young on 12-10-29.
//  Copyright (c) 2012年 young. All rights reserved.
//

#include <iostream>

class Point  {
public:
    int x;
    int y;
};
#include "file2.h"
#include "s.h"

using namespace std;

s s2;
void f2()
{
    s2.a.x = 10;
    s2.a.y = 10;
    
    s2.b = 'b';
    
    
    cout << "Now in file2 f2()..." << endl;
    cout << "s.a = " << s2.a.x << " " << s2.a.y << endl;
    cout << "s.b = " << s2.b << endl;
    
}