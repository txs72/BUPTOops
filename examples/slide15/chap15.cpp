class Task{
    //...
    virtual debug_info* get_debug();
};
class Displayed {
    //...
    virtual debug_info* get_debug();
};

void f(Satellite* sp)
{
    debug_info* dip = sp->get_debug();
    dip = sp->Task::get_debug();
    dip=sp->Displayed::get_debug();
}


class Task{ void debug(double p); };
class Displayed{ void debug(int v); };
class Satellite:public Task, public Displayed{/*...*/}

void g(Satellite* p){
    p->debug(1);
    p->Task::debug(1);
    p->Displayed::debug(1);
}

class A{ public: int f(int); char f(char); };
class B{ public: double f(double); };
class AB:public A, public B{
public:
    using A::f;
    using B::f;
    char f(char);
    AB f(AB);
};

void g(AB& ab){
    ab.f(1);
    ab.f('a');
    ab.f(2.0);
    ab.f(ab);
}

struct Link { Link *next; };

void mess_with_links(Satellite* p){
    p->next = 0;
    p->Link::next = 0;
    p->Task::next = 0;
    p->Displayed::next = 0;
}


class Storable{ public: virtual void write() = 0;};
class Transimitter: public Storable{ public: void write();};
class Receiver:public Storable{ public: void write(); };
class Radio:public Transimitter, public Receiver{
    void write(); };
void Radio::write(){
    Transmitter::write();
    Receiver::write(); }

class Storable{
public:
    Storable(const char* s);
    virtual void read() = 0;
    virtual void write() = 0;
    virtual ~Storable();
private:
    const char* store;
    Storable(const Storable&);
    Storable& operator=(const Storable&);
};


class A{ /*...*/ };
class B{ public: B(); };
class C{ public: C(int); };
class D:virtual public A, virtual public B, virtual public C{
    D(){/*...*/}
    D(int i):C(i){/*...*/};
};


class Window{ 
    // 
    virtual void draw();
};

class Window_with_border:public virtual Window{
    // border
    void own_draw();
    void draw();
};
class Window_with_menu:public virtual Window{
    void own_draw();
    void draw();
};

class Buffer{
protected:
    char a[128];
};
class Linked_buffer:public Buffer{/*...*/};
class Cyclic_buffer:public Buffer{
    void f(Linked_buffer* p){
        a[0] = 0;
        p->a[0] = 0;
    }
};

class X:public B{};
class Y:protected B{};
class Z:private B{};


struct B{
    int m;
    static int sm;
};

class D1:public virtual B{/*...*/};
class D2:public virtual B{/*...*/};
class DD:public D1, private D2{/*...*/};

DD* pd = new DD;
B* pb = pd;
int i1 = pd->m;

class X1:public B{/*...*/};
class X2:public B{/*...*/};
class XX:public X1,public X2{/*...*/};

XX* pxx = new XX;
int i1 = pxx->m;
int i2 = pxx->sm;


class B{
private: int a;
protected: int b;
public: int c;
};

class D:public B{
public:
    using B::a;
    using B::b;
};

void my_event_handler(BBWindow* pw){
    if(Ival_box* pb = dynamic_cast<Ival_box*>(pw)){
        pb->do_something();
    }
    else{
        //...
    }
}

class BB_ival_slider:public Ival_slider, protected BBslider{};
void f(BB_ival_slider* p){
    Ival_slider* pil = p;
    Ival_slider* pi1 = dynamic_cast<Ival_slider*>(p);
    BBslider* pbb1 = p;
    BBslider* pbb2 = dynamic_cast<BBslider*>(p);
}

class My_slider:public Ival_slider{//
};
class My_date:public Date{ //
};
void g(Ival_box* pb, Date* pd){
    My_slider* pd1 = dynamic_cast<My_slider*>(pb);
    My_date* pd2 = dynamic_cast<My_date*>(pd);
}

void f(Ival_box* p, Ival_box& r){
    if(Ival_slider* is = dynamic_cast<Ival_slider*>(p)){
        // yes
    }
    else{
        //*p 
    }
    Ival_slider& is = dynamic_cast<Ival_slider&>(r);
}

class Component:public virtual Storable{/*...*/};
class Record:public Component{/*...*/};
class Transmitter:public Component{/*...*/};
class Radio:public Receiver, public Transmitter{/*...*/};

void h1(Radio& r){
    Storable* ps = &r;
    Component* pc = dynamic_cast<Component*>(ps);
}


void g(Radio& r){
    Receiver* prec = &r;
    Radio* pr = static_cast<Radio*>(prec);
    pr = dynamic_cast<Radio*>(prec);

    Storable* ps = &r;
    pr = static_cast<Radio*>(ps);
    pr = dynamic_cast<Radio*>(ps);
}

Radio* f(void* p){
    Storable* ps = static_cast<Storable*>(p);
    return dynamic_cast<Radio*>(ps);
}

class type_info{
public:
    virtual ~type_info();
    bool operator==(const type_info&)const;
    bool operator!=(const type_info&)const;
    bool before(const type_info&)const;
    const char* name() const;
private:
    type_info(const type_info&);
    type_info& operator=(const type_info&);
};
    

class type_info;
const type_info& typeid(type_name) throw();
const type_info& typeid(expression) throw(bad_typeid);


class Std_interface{
public:
    virtual void start() = 0;
    virtual void suspend() = 0;
    virtual void resume() = 0;
    virtual void quit() = 0;
    virtual void full_size() = 0;
    virtual void small() = 0;
    virtual ~Std_interface() {}
};

typedef void (Std_interface::*Pstd_mem)();
void f(Std_interface* p){
    Pstd_mem s = &Std_interface::suspend;
    p->suspend();
    (p->*s)();
}

class Employee{
public:
    void* operator new(size_t);
    void operator delete(void*, size_t);
};

void* Employee::operator new(size_t){
    //
}
void Employee::operator delete(void* p, size_t s){
    //
}


class Manager:public Employee {
    int level;
};

void f(){
    Employee* p = new Manager;
    delete p;
}

class Employee {
public:
    void* operator new(size_t);
    void operator delete(void*, size_t);
    virtual ~Employee();
};
