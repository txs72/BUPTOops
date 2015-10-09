struct Link{
    Link* pre; Link* suc;
};
class List{
    Link* head;
    Link* curr;
public:
    Link* get();
    void put(Link*);
};
class Ship:public Link{/*...*/};
void f(List* lst){
    while(Link* po=lst->get()){
        if(Ship* ps = dynamic_cast<Ship*>(po)){
               //...
        }
        else {
            //...
        }
    }
}

class Container:public Object{
public:
    virtual Object* get();
    virtual void put(Object*);
    virtual Object*& operator[](size_t);
};

class List:public Container{
public:
    Object* get();
    void put(Object*);
};

class Vector:public Container{
public:
    Object*& operator[](size_t);
};


template<class C> typename C::value_type sum(const C& c)
{
typename C::value_type s = 0;
typename C::const_iterator p = c.begin() ; // start at the beginning
while (p!=c.end()) { // continue until the end
s += *p; // get value of element
++p; // make p point to next element
}
return s;
}

template <class T, class A = allocator<T> > class vector {
public:
// ...
// iterators:
iterator begin() ; // points to first element
const_iterator begin() const;
iterator end() ; // points to onepastlast
element
const_iterator end() const;
reverse_iterator rbegin() ; // points to first element of reverse sequence
const_reverse_iterator rbegin() const;
reverse_iterator rend() ; // points to onepastlast
element of reverse sequence
const_reverse_iterator rend() const;
// ...
};

template<class C>
typename C::iterator find_last(const C& c, typename C::value_type v)
{
return find_first(c.rbegin() ,c.rend() ,v).base() ;
}

template<class C>
typename C::iterator find_last(const C& c, typename C::value_type v)
{
typename C::iterator p = c.end() ; //search backwards from end
while (p!=c.begin()) {
p;
if (*p==v) return p;
}
return p;
}


template<class C>
typename C::reverse_iterator find_last(const C& c, typename C::value_type v)
{
typename C::reverse_iterator p = c.rbegin() ; // view sequence in reverse order
while (p!=c.rend()) {
if (*p==v) return p;
++p; // note: not decrement ()
}
return p;
}


template <class T, class A = allocator<T> > class vector {
public:
// ...
// element access:
reference operator[](size_type n) ; // unchecked access
const_reference operator[](size_type n) const;
reference at(size_type n) ; // checked access
const_reference at(size_type n) const;
reference front() ; // first element
const_reference front() const;
reference back() ; // last element
const_reference back() const;
// ...
};



void f(vector<int>& v, int i1, int i2)
try {
for(int i = 0; i < v.size() ; i++) {
// range already checked: use unchecked v[i] here
}
v.at(i1) = v.at(i2) ; // check range on access
// ...
}
catch(out_of_range) {
// oops: outofrange
error
}



void f(vector<double>& v)
{
double d = v[v.size()] ; // undefined: bad index
list<char> lst;
char c = lst.front() ; // undefined: list is empty
}


template <class T, class A = allocator<T> > class vector {
public:
// ...
// constructors, etc.:
explicit vector(const A& =A()) ;
explicit vector(size_type n, const T& val = T() , const A& =A()) ; // n copies of val
template <class In> // In must be an input iterator (¡ì19.2.1)
vector(In first, In last, const A& =A()) ; // copy from [first:last[
vector(const vector& x) ;
~vector() ;
vector& operator=(const vector& x) ;
template <class In> // In must be an input iterator (¡ì19.2.1)
void assign(In first, In last) ; // copy from [first:last[
void assign(size_type n, const T& val) ; // n copies of val
// ...
};


vector<Record> vr(10000) ;
void f(int s1, int s2)
{
vector<int> vi(s1) ;
vector<double>* p = new vector<double>(s2) ;
}


class Num{ // infinite precision
public:
Num(long) ;
// no default constructor
// ...
};
vector<Num> v1(1000) ; // error: no default Num
vector<Num> v2(1000,Num(0)) ; // ok


void f(int i)
{
vector<char> vc0(1)
; // fairly easy for compiler to warn against
vector<char> vc1(i) ;
}
void g()
{
f(1)
; // trick f() into accepting a large positive number!
}


void f(const list<X>& lst)
{
vector<X> v1(lst.begin() ,lst.end()) ; // copy elements from list
char p[] = "despair";
vector<char> v2(p,&p[sizeof(p)1])
; // copy characters from Cstyle
string
}

void f1(vector<int>&) ; // common style
void f2(const vector<int>&) ; // common style
void f3(vector<int>) ; // rare style
void h()
{
vector<int> v(10000) ;
// ...
f1(v) ; // pass a reference
f2(v) ; // pass a reference
f3(v) ; // copy the 10000 elements into a new vector for f3() to use
}


class Book {
// ...
};
void f(vector<Num>& vn, vector<char>& vc, vector<Book>& vb, list<Book>& lb)
{
vn.assign(10,Num(0)) ; // assign vector of 10 copies of Num(0) to vn
char s[] = "literal";
vc.assign(s,&s[sizeof(s)1])
; // assign "literal" to vc
vb.assign(lb.begin() ,lb.end()) ; // assign list elements
// ...
}

void f()
{
vector<char> v(10,¡äx¡ä) ; // v.size()==10, each element has the value ¡¯x¡¯
v.assign(5,¡äa¡ä) ; // v.size()==5, each element has the value ¡¯a¡¯
// ...
}


void f2(vector<Book>& vh, list<Book>& lb)
{
vector<Book> vt(lb.begin() ,lb.end()) ;
vh = vt;
// ...
}

template <class T, class A = allocator<T> > class vector {
public:
// ...
// stack operations:
    void push_back(const T& x) ; // add to end
    void pop_back() ; // remove last element
// ...
};


void f(vector<char>& s)
{
s.push_back(¡äa¡ä) ;
s.push_back(¡äb¡ä) ;
s.push_back(¡äc¡ä) ;
s.pop_back() ;
if (s[s.size()1]
!= ¡äb¡ä) error("impossible!") ;
s.pop_back() ;
if (s.back() != ¡äa¡ä) error("should never happen!") ;
    }
    
    
    template <class T, class A = allocator<T> > class vector {
    public:
// ...
// list operations:
        iterator insert(iterator pos, const T& x) ; // add x before ¡¯pos¡¯
        void insert(iterator pos, size_type n, const T& x) ;
        template <class In> // In must be an input iterator (¡ì19.2.1)
        void insert(iterator pos, In first, In last) ; // insert elements from sequence
        iterator erase(iterator pos) ; // remove element at pos
        iterator erase(iterator first, iterator last) ; // erase sequence
        void clear() ; // erase all elements
// ...
    };




vector<string> fruit;
fruit.push_back("peach") ;
fruit.push_back("apple") ;
fruit.push_back("kiwifruit") ;
fruit.push_back("pear") ;
fruit.push_back("starfruit") ;
fruit.push_back("grape") ;


sort(fruit.begin() ,fruit.end()) ;
vector<string>::iterator p1 = find_if(fruit.begin() ,fruit.end() ,initial(¡äp¡ä)) ;
vector<string>::iterator p2 = find_if(p1,fruit.end() ,initial_not(¡äp¡ä)) ;
fruit.erase(p1,p2) ;

template<class C> void f(C& c)
{
c.erase(c.begin()+7) ; // ok
c.erase(&c[7]) ; // not general

    c.erase(c+7) ; // error: adding 7 to a container makes no sense
c.erase(c.back()) ; // error: c.back() is a reference, not an iterator
c.erase(c.end()2)
; // ok (second to last element)
c.erase(c.rbegin()+2) ; // error: vector::reverse_iterator and vector::iterator
// are different types
c.erase((c.rbegin()+2).base()) ; // obscure, but ok (see ¡ì19.2.5)
}


template <class T, class A = allocator<T> > class vector {
public:
// ...
// capacity:
size_type size() const; // number of elements
bool empty() const { return size()==0; }
size_type max_size() const; // size of the largest possible vector
void resize(size_type sz, T val = T()) ; // added elements initialized by val
size_type capacity() const; // size of the memory (in number of elements) allocated
void reserve(size_type n) ; // make room for a total of n elements; don¡¯t initialize
// throw a length_error if n>max_size()
// ...
};


template <class T, class A = allocator<T> > class vector {
public:
// ...
void swap(vector&) ;
allocator_type get_allocator() const;
};


template <class T, class A>
bool std::operator==(const vector<T,A>& x, const vector<T,A>& y) ;
template <class T, class A>
bool std::operator<(const vector<T,A>& x, const vector<T,A>& y) ;


template <class T, class A>
inline bool std::operator<(const vector<T,A>& x, const vector<T,A>& y)
{
return lexicographical_compare(x.begin() ,x.end() ,y.begin() ,y.end()) ;// see ¡ì18.9
}

void f(vector<bool>& v)
{
for (int i = 0; i<v.size() ; ++i) cin >> v[i] ; // iterate using subscripting
typedef vector<bool>::const_iterator VI;
for (VI p = v.begin() ; p!=v.end() ; ++p) cout<<*p; // iterate using iterators
}



