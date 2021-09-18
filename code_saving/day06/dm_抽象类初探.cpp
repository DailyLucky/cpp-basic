#include <iostream>

using namespace std;


// 定义一个父类
class Parent { 
public:
	Parent(int _a, int _b) {
		a = _a;
		b = _b;
		cout << "Parent constructor has been executed!" << endl;
	}
	~Parent() {
		//cout << "Parent destructor has been executed!" << endl;
	}
	virtual void print() {
		cout << "a: " << a << "  b: " << b << endl;
	}
	virtual void PureFunc() = 0;
public:
	int a;
	int b;
};


class Child1 : public Parent {
public:
	Child1 (int _a, int _b, int _c) : Parent(_a, _b) {
		c = _c;
		cout << "Child1 constructor has been executed!" << endl;
	}
	~Child1 () {
		//cout << "Child1 destructor has been executed!" << endl;
	}
	virtual void print() {
		cout << "a: " << a << "  b: " << b << "  c: " << c << endl;
	}
	virtual void PureFunc();
public:
	int c;
};

class GrandChild3 : public Child1 {
public:
	GrandChild3 (int _a, int _b, int _c) : Child1(_a, _b,_c) {
		// c = _c;
		// cout << "Child1 constructor has been executed!" << endl;
	}
};
// 多态实现
// void objplay(Parent *obj) { 
// 	obj->print(); // 同一个调用会产生不同的现象
// }

int main() {
	Child1 c1(4, 3, 2);
	GrandChild3 gc3(1,2,3);
	cout << "Run here!" << endl;
	return 0;
}