class String
{
    struct Srep; // 表示
    Srep *rep; 
public:
    class Cref; // 引用char
    class Range{}; // 用于异常
};

struct String::Srep
{
    char* s; // 到元素的指针
    int sz; // 字符个数
    int n; //  引用计数
    Srep(int nsz, const char* p)
    {
        n = 1;
        sz = nsz;
        s = new char[sz+1];
        strcpy(s,p);
    }
    ~Srep() { delete[] s; }
    Srep* get_own_copy()
    {
        if(n==1) return this;
        n--;
        return new Srep(sz,s);
    }
    void assign(int nsz, const char* p)
    {
        if(sz!=nsz) {
            delete[] s;
            sz = nsz;
            s = new char[sz+1];
        }
        strcpy(s,p);
    }
private:
    Srep(const Srep&);
    Srep& operator=(const Srep&);
};

class String
{
    //...
    String();
    String(const char*);
    String(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    ~String();
};
String::String()
{
    rep = new Srep(0,"");
}
String::String(const String& x)
{
    x.rep->n++;
    rep = x.rep; // 共享表示
}

String:~String()
{
    if(--rep->n==0) delete rep;
}

String& String::operator=(const String& x) //赋值复制
{
    x.rep->n++; // 保护，防止"st=st"
    if(--rep->n==0) delete rep;
    rep = x.rep;
    return *this;
}

String::String(const char* s)
{
    rep = new Srep(strlen(s),s);
}

String& String::operator=(const char* s)
{
    if(rep->n == 1) // 再利用Srep
        rep->assign(strlen(s),s);
    else{ // 使用新的Srep
        rep->n--;
        rep = new Srep(strlen(s),s);
    }
    return *this;
}
// 对字符串的访问运算符
class String
{
    void check(int i) const {
        if(i<0 || rep->sz<=i) throw Range();
    }
    char read(int i) const { return rep->s[i]; }
    void write(int i, char c){
        rep = rep->get_own_copy();
        rep->s[i] = c;
    }
    Cref operator[](int i){
        check(i);
        return rep->s[i];
    }
    char operator[](int i) const {
        check(i);
        return rep->s[i];
    }
    int size() const{ return rep->sz; }
};

int hash(const String& s)
{
    int h = s.read(0);
    const int max = s.size();
    for(int i=1;i<max;i++)
        h^=s.read(i)>>i;
    return h;
}

class String::Cref
{
friend class String;
    String& s;
    int i;
    Cref(String& ss, int ii):s(ss),i(ii){}
public:
    operator char() const { return s.read(i); }
    void operator=(char c){s.write(i,c); }
};

//eg
void f(String s, const String& r)
{
    char c1 = s[1];
    s[1] = 'c';
    char c2 = r[1];
    r[1] = 'd';
}

class String
{
    String& operator+=(const String&);
    String& operator+=(const char*);

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);

    friend bool operator==(const String& x, const char* s)
        { return strcmp(x.rep->s,s)==0; }
    friend bool operator==(const String& x, consts String& y)
        { return strcmp(x.rep->s,y.rep->s)==0; }
    friend bool operator!=(const String& x, const char* s)
        { return strcmp(x.rep->s,s)!=0; }
    friend bool operator!=(const String& x, consts String& y)
        { return strcmp(x.rep->s,y.rep->s)!=0; }
};

String operator+(const String&, const String&);
String operator+(const String&, const char*);

String f(String a, String b)
{
    a[2] = 'x';
    char c = b[3];
    cout << "inf f: " << a << ' '<< b << ' ' << c << '\n';
    return b;
}

int main()
{
    String x,y;
    cout << "Please enter two strings\n";
    cin >> x >> y;
    cout << "input: " << x << ' ' << y << '\n';
    String z = x;
    y = f(x,y);
    if(x!=z) cout << "x corrupted!\n";
    x[0] = '!';
    if(x==z) cout << "write failed\n";
    cout << "exit: " << x << ' ' << y << ' ' << z << '\n';
}
