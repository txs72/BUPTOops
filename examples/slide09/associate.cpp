#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
//using namespace std;

class Assoc {
    struct Pair {
        string name;
        double val;
        Pair(string n="",double v=0):name(n), val(v) {}
    };
    vector<Pair> vec;
    Assoc(const Assoc&); //私用，防止复制
    Assoc& operator=(const Assoc&);//私用，防止复制
public:
    Assoc(){}
    //const double& operator[](const string&);
    double& operator[](string&);
    void print_all() const;
};

void Assoc::print_all() const{
    cout << "最终统计结果" << endl;
    for(vector<Pair>::const_iterator p=vec.begin();
        p!=vec.end();++p)
        cout << p->name<<":"<<p->val<<'\n';
}

double& Assoc::operator[](string& s){
// 检索s；如果找到就返回其值；
// 否则，做一个新的Pair并返回默认值0
    for(vector<Pair>::iterator p = vec.begin();
        p!=vec.end(); ++p)
            if(s==p->name) return p->val;
    vec.push_back(Pair(s,0));
    return vec.back().val;
}

int main()
// 计算每一个单词在输入时出现的次数
{
    string buf;
    Assoc vec;
    while(cin>>buf) { 
        //if(buf == "exit") break;
        vec[buf]++;
    }
    vec.print_all();
}
