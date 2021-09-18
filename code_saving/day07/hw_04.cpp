// 4. 简述什么是纯虚函数，意义何在？
/*
纯虚函数就是在父类中不实现，要求子类必须实现的子类自己版本的函数。它可以起到定义接口的作用。
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


