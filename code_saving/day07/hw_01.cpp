// 1. 简述多态的原理，和vptr指针。
/*
 如果在父类中用virtual关键字声明了函数，那么C++编译器就会有相应的处理。它会为我们生成vptr指针，维护虚函数表。
 当我们调用virtual修饰的函数时，是通过vptr指针去找到对应的函数。表面上看着就是我们传入了谁，就调用谁实现的虚函数。
 实际上并不是编译器有这么智能，它实际上也是通过查找虚函数表中的函数指针进行的调用。
 */
#include <iostream>

using namespace std;

class Parent {
public:
	Parent(int a = 0, int b = 0) : m_a(a), m_b(b) {}
	virtual void func() {
		cout << "a: " << m_a << "  b: " << m_b << endl;
	}
public:
	int m_a;
	int m_b;
};
class Child : public Parent {
public:
	Child(int a=0, int b=0, int c=0) : Parent(a, b) {
		m_c = c;
	}
	virtual void func() {
		cout << "a: " << m_a << "  b: " << m_b << "  c: " << m_c << endl;
	}
public:
	int m_c;
};

void CallWho(Parent *who) {
	who->func();
}

int main() {
	Parent t1(1, 9);
	Child c1(100, 200, 300);
	CallWho(&t1);
	CallWho(&c1);

	cout << "Run here!" << endl;
	return 0;
}


