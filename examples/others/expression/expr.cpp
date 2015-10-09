#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
// #include <conio.h>

#define MAX_DIGIT_LEN		64
#define STACK_DEPTH			300
#define MAX_EXPRESSION_LEN	80
#define _ASSERT(a)			(a) ? 1 : printf("\nError code:\t%s\nFile:\t\t%s\nLine:\t\t%d\r\n",#a,__FILE__,__LINE__)
const char operators[] = {'+', '-', '*', '/', '(', ')'};
int priority[7][7] = {		// < 运算符的优先级比较矩阵 >
	{0, 0, 1, 1, 1, 0},		// 该矩阵不是对称的，即优先级
	{0, 0, 1, 1, 1, 0},		// 的大小和运算符所处的位置有关
	{0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 0},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
};

template <class Type> class List;		// 前视的类定义
template <class Type> class ListNode {	// 链表结点类的定义
	friend class List<Type>;			// List类作为友元类定义
private:
	Type data;						// 数据域
	ListNode<Type> *prev, *next;			// 链指针域
public:
	ListNode ( ) {
		prev = NULL;
		next = NULL;
	}
	
	ListNode ( const Type& item ) {
		data = item;
		prev = NULL;
		next = NULL;
	}
	
	ListNode ( const Type& item, ListNode<Type>* prev, ListNode<Type>* next ) {
		data = item;
		this->prev = prev;
		this->next = next;
	}
	
	ListNode<Type> *PrevNode ( ) { return prev; }	//给出当前结点的上一个结点地址
	ListNode<Type> *NextNode ( ) { return next; }	//给出当前结点的下一个结点地址

	void InsertAfter ( ListNode<Type> *p ) {		//当前结点插入
		_ASSERT(p != NULL);
		if (next != NULL) next->prev = p;
		p->next = next;  next = p; p->prev = this;
	}	
};

template <class Type> 
class List {						//单链表类定义
private:
	ListNode<Type> *first, *last;	//链表的表头指针, 表尾指针
public:
	List ( ) {					//构造函数, 建立一个空链表
		last = first = new ListNode<Type> ( ); 
	}	
	
	~List ( ) {					//析构函数
		MakeEmpty ( );  
		delete first;  
		first = last = NULL;
	}
	
	int IsEmpty() {
		return (first==last);
	}

	void MakeEmpty ( ) {		//将链表置为空表
		ListNode<Type> *q;
		while ( first->next != NULL ) {	//当链不空时, 删去链中所有结点
			q = first->next;  first->next = q->next;
			delete q;			//循链逐个删除，保留一个表头结点
		}
		last = first;			//表尾指针指向表头结点
	}
	
	int Length ( ) const{		//计算链表的长度
		int count = 0;
		ListNode<Type> *p = first->next;  
		while ( p != NULL ) {	//循链扫描, 寻找链尾
			p = p->next;  
			count++; 
		}
		return count;
	}
	
	ListNode<Type> *GetNode ( const Type& item, ListNode<Type> *prev, ListNode<Type> *next ) 
	{//建立一个新结点
		ListNode<Type> *newnode = new ListNode<Type> ( item, prev, next );
		return newnode;
	}
	
	int Append ( Type value ){	//将新元素value插入在链表中第i个位置
		ListNode<Type> *newnode = GetNode (value, NULL, NULL);//创建含value的结点
		last->InsertAfter(newnode);
		last = newnode;			//插入成功，函数返回1
		return 1;
	}
	
	Type RemoveTail (){	//将链表中的第i个元素删去
		ListNode<Type> *q;	// p定位于第i-1个元素
		if (first == last) {
			return NULL;
		}

		Type value = last->data;	//取出被删结点中的数据值
		q = last;					//删表尾结点时, 表尾指针修改
		last = last->prev;
		last->next = q->next;
		delete q;  
		return value;
	}
	
	int GetTail(Type &node) {
		if (first == last) {
			return 0;
		}

		node = last->data;
		return 1;
	}
};

template <class T> 
class Stack {
private:
	List<T> list;
public:
	Stack() {			
	}

	int Push(T node) {	// 进栈操作
		return list.Append(node);
	}

	int Pop(T& node) {	// 出栈操作
		if (!list.IsEmpty()) {// 栈是否为空
			node = list.RemoveTail();
			return 1;
		}
		return 0;
	}

	void Print() {	// 输出栈数据(为调试所用)
		for (int i = 0; i < top; i ++) {
			switch (sizeof(T)) {
			case sizeof(int):  printf("%d\n", data[i]); break;
			case sizeof(char): printf("%c\n", data[i]); break;
			default:		   printf("Unknown data type.\n"); return;
			}
		}
	}

	T Top() {	// 取顶操作
		T node;
		_ASSERT(!list.IsEmpty());
		list.GetTail(node);
		return node;
	}
};

class Expr {
private:
	Stack<double> Operands;	// 操作数栈
	Stack<char  > Operators;// 运算符栈
	int Length;				// 表达式长度
	// 表达式的字符表示
	char Expression[MAX_EXPRESSION_LEN];
public:
	// 为了方便运算符的比较，设置一个'('作为哨兵，
	// 可以有效地防止越界，在表达式最后添加一个')'
	// 来与其形成呼应。
	Expr(char *expr) {	// 构造函数
		Length = strlen(expr) + 1;
		_ASSERT(MAX_EXPRESSION_LEN > Length);

		memcpy(Expression, expr, Length);
		Expression[Length - 1] = ')';
		Expression[Length] = '\0';

		_ASSERT(Operators.Push('('));
	}

	// 运算符在运算符表(operators)中所处的位置
	int Index(char n) {
		char *pos = strrchr(operators, n);
		if (pos != NULL) {
			return pos - operators;
		} 
		return -1;
	}

	// 运算函数
	int eval() {
		char op;	// 当前运算符
		double cx, ly, res;
		char *cexp;	// 当前表达式扫描位置
		
		for (int i = 0; i < Length; i ++) {
			cexp = Expression + i;	// 设置扫描位置
			if (isdigit(Expression[i])){
				// 获得当前位置的数值
				_ASSERT(Operands.Push(strtod(cexp, &cexp)));
				i = cexp - Expression;
			}

			if (Index(Expression[i]) != -1) {
				// 如果当前运算符的优先级小于栈顶运算符优先级，
				// 取出栈顶操作数作相应计算，结果入栈
				while (!priority[Index(Operators.Top())][Index(Expression[i])]) {
					_ASSERT(Operands.Pop(ly));
					_ASSERT(Operands.Pop(cx));
					_ASSERT(Operators.Pop(op));

					switch (Index(op)) {
					case 0: res = cx + ly; break;
					case 1: res = cx - ly; break;
					case 2: res = cx * ly; break;
					case 3: res = cx / ly; break;
					default:
						printf("Error Expression.\n");
						exit(1);
					}
					
					_ASSERT(Operands.Push(res));
				}

				if (Expression[i] != ')') {	// 右括号不需要入栈			
					_ASSERT(Operators.Push(Expression[i]));
				} else if (Operators.Top() == '(') {
					// 如果左右括号相遇，则左括号出栈
					Operators.Pop(op);
				}
			}
		}
		// 返回计算结果，从浮点到整数采取四舍五入策略
		res = Operands.Top();
		return (res > 0) ? res + 0.5 : res - 0.5;
	}

	void print() {
		printf("%d\n", eval());
	}
};

void main(int argc, char* argv[])
{
	int len;
	char c, expression[MAX_EXPRESSION_LEN];
	printf("Input the expression and press ENTER to get the result:\n");
	printf("\tOnly 0,1,...,9 and %s is accepttable.\n", operators); 
	while(true) {
		len = 0;
		while (len < MAX_EXPRESSION_LEN) {			
			c = _getch();

			if (c == '\r') {
				if (len == 0) {
					printf("Hey man, input something!\n");
					continue;
				}

				printf(" = ");
				break;
			}

			if (isdigit(c) || strrchr(operators, c) != NULL) {
				printf("%c", c);
			} else {
				if (tolower(c) == 'q') return;
				printf("Invalid input.\n");
				continue;
			}
	
			expression[len ++] = c;
		}

		expression[len] = 0;
		Expr expr(expression);
		expr.print();
	}
}
