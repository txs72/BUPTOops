#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pair {
    string name;
    double val;
};

vector<Pair> pairs;

double& value(const string& s)
{
    for(int i=0; i<pairs.size(); i++)
        if(s==pairs[i].name) return pairs[i].val;

    Pair p = {s, 0};
    pairs.push_back(p);
    return pairs[pairs.size()-1].val;
}

int main()
{
    string buf;
    while(cin>>buf) value(buf)++;

    for(vector<Pair>::const_iterator p = pairs.begin();p!=pairs.end(); ++p)
        cout << p->name << ":" << p->val << endl;
    return 0;
}

