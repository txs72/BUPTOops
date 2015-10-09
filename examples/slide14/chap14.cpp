class Matherr{};
class Overflow:public Matherr{};
class Underflow:public Matherr{};
class Zerodivide:public Matherr{};

void f()
{
    try {
    }
    catch(Overflow){
    }
    catch(Matherr){
    }
}

void g()
{
    try{
        //...
    }
    catch(Overflow){/*...*/}
    catch(Underflow){/*...*/}
    catch(Zerodivice){/*...*/}
}

class matherr{
    //...
    virtual void debug_print() const {
        ceer << "Math error"; 
    }
};

class Int_overflow:public Matherr{
    const char* op;
    int a1, a2;
public:
    Int_overflow(const char* p, int a, int b)
    {
        op = p; a1 = a; a2 = b;
    }
    virtual void debug_print() const {
        cerr << op << a1 << a2;
    }
};

void f()
{
    try { g(); }
    catch(Matherr m){/*...*/ }
}

class Netfile_err:public Network_err, public File_system_err
{/*...*/};

void f()
{
    try{
        throw E();
    }
    catch(H){
        //何时运行到这里？
    }
}

void h()
{
    try {
        // 可能抛出Matherr的代码
    }
    catch(Matherr){
        if(can_handle_it_completed){
            //处理Matherr
            return;
        }
        else{
            //完成这里能做的事情
            throw;
        }
    }
}

void m()
{
    try {
        // 一些代码
    }
    catch(...) {//处理所有异常
        // 清理工作 
        throw;
    }
}

void f() {
    try{
        //...
    }
    catch(std::ios_base::failure){
        //处理任何流io错误
    }
    catch(std::exception& e){
        //处理所有标准库异常
    }
    catch(...){
        //处理任何其他异常
    }
}

void use_file(const char* fn)
{
    FILE* f = fopen(fn, "r");
    // use f
    fclose(f);
}

void use_file(const char* fn) {
    FILE* f = open(fn, "r");
    try {
        // 使用f
    }
    catch(...){
        fclose(f);
        throw;
    }
    fclose(f);
}

void acquire()
{
    // 申请资源1
    // ...
    // 申请资源n

    // 使用资源
    // 释放资源n
    // ...
    // 释放资源1
}



class File_ptr{
    FILE* p;
public:
    File_ptr(const char* n, const char* a){p=fopen(n,a);}
    File_ptr(FILE* pp) { p=pp; }
    // 适当的复制机制
    ~File_ptr() { if(p) fclose(p); }
    operator FILE*() { return p; }
};

class X{
    File_ptr aa;
    Lock_ptr bb;
public:
    X(const char* x, const char* y)
        :aa(x,"rw"), // 申请'x'
         bb(y)// 申请y
    {}
};

class Y{
    int* p;
    void init();
public:
    Y(int s) { p=new int(s); init(); }
    ~Y(){delete[] p;}
    //...
};

class Z{
    vector<int> p;
    void init();
public:
    Z(int s) : p(s) { init(); }
    // ...
};

void f(Point p1, Point p2, auto_ptr<Circle> pc, Shape* pb)
{
    auto_ptr<Shape> p(new Rectangle(p1,p2)); // p指向一个矩形
    auto_ptr<Shape> pbox(pb);
    
    p->rotate(45); // auto_ptr<Shape>的使用与Shape*一样
    // ...
    if(in_a_mess) throw Mess();
}

template<class X> class std::auto_ptr{
    template<class Y> struct auto_ptr_ref{/*...*/};
    X* ptr;
public:
    typedef X element_type;
    explicit auto_ptr(X* p=0) throw(){ptr=p;}
    ~auto_ptr() throw() { delete ptr; }
    //注意，复制构造函数和赋值都用非const参数
    auto_ptr(auto_ptr& a) throw();
    template<class Y> auto_ptr(auto_ptr<Y>& a) throw();
    auto_ptr& operator=(auto_ptr& a) throw();
    template<class Y> auto_ptr& operator=(auto_ptr<Y>& a) throw();
    
    X& operator*() const throw() { return *ptr; }
    X* operator->() const throw() { return ptr; }
    X* get() const throw() { return ptr; }
    X* release() throw() { X* t=ptr; ptr=0; return t; }
    void reset(X* p=0) throw() { if(p!=ptr) {delete ptr; ptr=p; }}
    
    auto_ptr(auto_ptr_ref<X>) throw();
    template<class Y> operator auto_ptr_ref<Y>() throw();
    template<class Y> operator auto_ptr<Y>() throw();
};
// auto_ptr_ref的用途就是为普通auto_ptr实现破坏性复制语义

void g(Circle* pc)
{
    auto_ptr<Circle> p2(pc);
    auto_ptr<Circle> p3(p2);
    p2->m = 7;
    Shape* ps = p3.get();
    auto_ptr<Shape> aps(p3);
    auto_ptr<Circle> p4(pc);
}

void f(Arena& a, X* buffer)
{
    X* p1 = new X;
    X* p2 = new X[10];
    
    X* p3 = new(&buffer[10])X;
    // 将X放入buffer(无需分配存储)
    X* p4 = new(&buffer[11])X[10];

    X* p5 = new(a)X;
    // 从分配场a分配存储(从a中释放)
    X* p6 = new(a)X[10];
}

void* operator new(size_t size)
{
    for(;;){
        if(void* p = malloc(size)) return p;
        if(_new_handler == 0) throw bad_alloc();
        _new_handler();
    }
}


void my_new_handler();
void f()
{
    void(*oldnh)() = set_new_handler(&my_new_handler);
    try{
        // ...
    }
    catch(bad_alloc){
        // ...
    }
    catch(...) {
        set_new_handler(oldnh);
        throw;
    }
    set_new_handler(oldnh);
}

class Vector{
public:
    class Size{};
    enum {max = 32000};
    Vector(int sz) {
        if(sz<0 || max<sz) throw Size();
        // ...
    }
};

Vector* f(int i)
{
    try {
        Vector* p = new Vector(i);
        // ...
        return p;
    }
    catch(Vector::Size){
        // 处理错误
    }
}


class X{
    Vector v;
public:
    X(int);
};

X::X(int s)
try 
:v(s)
{
    // ...
}

catch(Vector::Size){
    // ...
}

X::~X()
    try {
    f();
    }
catch(...){
    // 
}

void f(Queue<X>& q)
    try {
    for(;;) {
        X m = q.get();
        // ...
    }
    }
catch(Queue<X>::Empty) {
    return;
}

void fnd(Tree* p, const string& s)
{
    if(s==p->str) throw p;
    if(p->left) fnd(p->left,s);
    if(p->right) fnd(p->right,s);
}

Tree* find(Tree* p, const string& s)
{
    try{
        fnd(p,s);
    }
    catch(Tree* q){
        return q;
    }
    return 0;
}

void f() throw(x2,x3)
{ /*...*/ }

void f()
try
 {
     // ...
 }
catch(x2){throw;}
catch(x3){throw;}
catch(...){
    std::unexpected();
}

int f() throw(std::bad_alloc);
int f() // 错误：缺少异常描述
{/*...*/}

class B{
public:
    virtual void f();
    virtual void g() throw(X,Y);
    virtual void h() throw(X);
};
class D : public B{
public:
    void f() throw(X);
    void g() throw(X);
    void h() throw(X,Y);
};

class Yunexpected:public Yerr{
public:
    Network_exception* pe;
    Yunexpected(Network_expection* p):pe(p?p->clone():0){}
    ~Yunexpected(){delete pe;}
};

void throwY() throw(Yunexpected)
{
    try{
        throw; //重新抛出将立即被捕捉
    }
    catch(Network_exception& p){
        throw Yunexpected(&p);
    }
    catch(...){
        throw Yunexpected(0);
    }
}

class exception{
public:
    exception() throw();
    exception(const exception&) throw();
    exception& operator=(const exception&) throw();
    virtual ~exception() throw();
    virtual const char* what() const throw();
private:
    // ...
};
