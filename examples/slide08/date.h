#include <string>

using namespace std;

class Date{
	int d,m,y;
    bool cache_valid;
    string cache;
//	mutable bool cache_valid;
//	mutable string cache;
	void compute_cache_value();
public:
	static Date default_date;
    // 构造函数 Constructor
    // 简称ctor
	Date(int d=0, int m=0, int y=0);  // 带默认参数的构造函数
	Date(const Date&); // 复制构造函数
	static void set_default(int, int, int);
	int getD() const;
	int getM() const;
	int getY() const;
	void setD(int);
	void setM(int);
	void setY(int);

    Date& add_year(int n);
    Date& add_month(int n);
    Date& add_day(int n);

	void print();
	// 逻辑的常量性
    string string_rep() const;
    // 这里，第一次调用string_rep时需要构造cache字符串

};
