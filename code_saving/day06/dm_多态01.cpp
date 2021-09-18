#include <iostream>

using namespace std;

// 多态实现的三个条件：
// 1. 要有继承
// 2. 要有虚函数重写
// 3. 要有父类指针(引用)指向子类对象

// 定义一个父类
class Parent { 
public:
	Parent(int _a, int _b) {
		a = _a;
		b = _b;
		//cout << "Parent constructor has been executed!" << endl;
	}
	~Parent() {
		//cout << "Parent destructor has been executed!" << endl;
	}
	virtual void print() {
		cout << "a: " << a << "  b: " << b << endl;
	}
public:
	int a;
	int b;
};


class Child1 : public Parent {
public:
	Child1 (int _a, int _b, int _c) : Parent(_a, _b) {
		c = _c;
		//cout << "Child1 constructor has been executed!" << endl;
	}
	~Child1 () {
		//cout << "Child1 destructor has been executed!" << endl;
	}
	virtual void print() {
		cout << "a: " << a << "  b: " << b << "  c: " << c << endl;
	}
public:
	int c;
};

// 多态实现
void objplay(Parent *obj) { 
	obj->print(); // 同一个调用会产生不同的现象
}

int main() {
	Parent p1(1, 2);
	Child1 c1(4, 3, 2);
	objplay(&p1);
	objplay(&c1);

	cout << "Run here!" << endl;
	return 0;
}