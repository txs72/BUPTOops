#include <string>
#include <vector>

using namespace std;

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
    double& operator[](string&);
    void print_all();
};

