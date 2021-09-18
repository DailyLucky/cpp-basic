#include <iostream>

using namespace std;

// 继承的两种名称关系：
// 父类 -- 子类
// 基类 -- 派生类
// 知道这种说法就行了

// 定义一个父类
class Parent { 
public:
	Parent(int _a, int _b, int _c) {
		this->a = _a;
		this->b = _b;
		this->c = _c;
		cout << "Parent constructor has been executed!" << endl;
	}
	~Parent() {
		cout << "Parent destructor has been executed!" << endl;
	}
	void print() {
		cout << "a: " << a << "  b: " << b << "  c: " << c << endl;
	}
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Child1 : public Parent {
public:
	Child1 (int a, int b, int c, int d) : Parent(a, b, c) {
		this->d = d;
		cout << "Child1 constructor has been executed!" << endl;
	}
	~Child1 () {
		cout << "Child1 destructor has been executed!" << endl;
	}
private:
	int d;
};

class Child2 : protected Parent {
public:
	Child2 (int a, int b, int c, int d) : Parent(a, b, c) {
		this->d = d;
		cout << "Child2 constructor has been executed!" << endl;
	}
	~Child2 () {
		cout << "Child2 destructor has been executed!" << endl;
	}
private:
	int d;
};

class Child3 : private Parent {
public:
	Child3 (int a, int b, int c, int d) : Parent(a, b, c) {
		this->d = d;
		cout << "Child3 constructor has been executed!" << endl;
	}
	~Child3 () {
		cout << "Child3 destructor has been executed!" << endl;
	}
private:
	int d;
};


int main() {
	Parent p1(1,2,3);
	Child1 c1(4,3,2,1);
	Child2 c2(4,3,2,1);
	Child3 c3(4,3,2,1);

	p1.print();
	c1.print();

	cout << "Run here!" << endl;
	return 0;
}