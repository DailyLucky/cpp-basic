#include <iostream>

using namespace std;
// 静态成员的初始化问题要引起注意

class Parent { 
public:
	Parent(int _a) {
		m_a = _a;
		//cout << "Parent constructor has been executed!" << endl;
	}
	~Parent() {
		//cout << "Parent destructor has been executed!" << endl;
	}
	void print() {
		cout << "a: " << m_a << endl;
	}
	void SMemberAdd() {
		s_s++;
	}
	int GetSMember() {
		return s_s;
	}
public:
	int m_a;
	static int s_s; // 父类中有一个静态成员变量
};

int Parent::s_s = 0; // 一般来说都要这样初始化一下，不然如果程序中有使用到这个静态时就会报错。

class Child1 : public Parent {
public:
	Child1 (int a, int b) : Parent(a) {
		m_b = b;
		//cout << "Child1 constructor has been executed!" << endl;
	}
	~Child1 () {
		//cout << "Child1 destructor has been executed!" << endl;
	}
private:
	int m_b;
};



int main() {
	Parent p1(1);
	Child1 c1(4,3);

	p1.print();
	c1.print();
	cout << p1.s_s << endl;
	c1.SMemberAdd();
	cout << c1.s_s << endl;
	p1.SMemberAdd();
	cout << c1.s_s << endl;

	cout << "Run here!" << endl;
	return 0;
}