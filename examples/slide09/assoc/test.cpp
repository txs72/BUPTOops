#include <iostream>

#include "assoc.h"

using namespace std;

int main()
// 计算每一个单词在输入时出现的次数
{
    string buf;
    Assoc vec;
    while(cin>>buf) vec[buf]++;
    vec.print_all();
}
