// 3. 可不可以用父类指针进行++操作来遍历子类对象数组？
/*
一般情况下是不能的，因为父类对象所占内存大小一定是小于等于子类的。当且仅当子类对象增加新的成员变量时才会相等，
如果在子类定义虚函数的话也是不行的，编译器会在这个子类添加vptr指针。

运行结果：
Initial...
pP: 0   pC: 0
After ++...
pP: 0x10   pC: 0x18
Run here!

从运行结果来看，子类这里还有4个填充字节。支持虚函数操作增加了8个字节，这里本来只有20字节，不过考虑和8的对齐，故
在最后还填充了4个字节。
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
	Parent *pP = NULL;
	Child *pC = NULL;
	cout << "Initial..." << endl;
	cout << "pP: " << pP << "   pC: " << pC << endl;
	pP++;
	pC++;
	cout << "After ++..." << endl;
	cout << "pP: " << pP << "   pC: " << pC << endl;


	cout << "Run here!" << endl;
	return 0;
}


