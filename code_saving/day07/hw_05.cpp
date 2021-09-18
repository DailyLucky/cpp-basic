// 5. 什么是抽象类？ 抽象类是否能够实例化。
/*
抽象类就是含有纯虚函数的类。它不能进行实例化。
其实继承它的子类也可以不实现纯虚函数，但是子类不实现该纯虚函数，则子类也不能实例化对象。
等到“孙子”实现了纯虚函数，那孙子就可以实例化。
 */
#include <iostream>

using namespace std;

class Parent {
public:
	Parent(int a = 0, int b = 0) : m_a(a), m_b(b) {}
	virtual void func() = 0;
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
	// Parent p1; // 含有纯虚函数的类不能实例化对象，这种类也被称为抽象类。
	Child c1;

	cout << "Run here!" << endl;
	return 0;
}


