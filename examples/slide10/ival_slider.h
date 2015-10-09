
#include "ival_box.h"

class Ival_slider : public Ival_box, protected BBwindow
{
public:
    Ival_slider(int, int);
    ~Ival_slider();
    int get_value();
    void set_value(int i);
    //..
protected:
    //覆盖BBwindow虚函数的函数
    //例如：draw(), mousehit()...
private:
    // slider所需要的数据
};// 多重继承的方式


