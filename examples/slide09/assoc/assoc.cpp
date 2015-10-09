#include <iostream>
#include "assoc.h"

using namespace std;

double& Assoc::operator[](string& s){
// 检索s；如果找到就返回其值；
// 否则，做一个新的Pair并返回默认值0
    for(vector<Pair>::iterator p = vec.begin(); p!=vec.end(); ++p)
            if(s==p->name) return p->val;
    vec.push_back(Pair(s,0));
    return vec.back().val;
}

void Assoc::print_all(){
    for(vector<Pair>::iterator p=vec.begin();
        p!=vec.end();++p)
        cout << p->name<<":"<<p->val<<'\n';
}


