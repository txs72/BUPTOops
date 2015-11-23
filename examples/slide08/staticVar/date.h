class Date { 
  int d,m,y; // 成员变量
  static Date default_date; // 静态成员变量 类成员变量
public:
  static int count;
  void init_date(int dd, int mm, int yy);
  void add_year(int n);
  void add_month(int n); 
  void add_day(int n); 
  void print();
  int getDay(){return d;};
  void setDay(int dd){ d = dd;}
  Date(int dd=0, int mm=0, int yy=0){
    d = dd? dd : default_date.d;
    m = mm? mm : default_date.m; 
    y = yy? yy : default_date.y;
    count ++;
  }
};

