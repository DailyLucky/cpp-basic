// 2. 如何证明virtual 虚函数中 vptr指针的存在。
/*
我们只需要在声明虚函数和不声明虚函数的情况下，分别sizeof(Test)一下就可以看到结果。
 */
#include <iostream>

using namespace std;

class Test {
public:
	Test(int a = 0, int b = 0) : m_a(a), m_b(b) {}
	virtual
	void func() {
		cout << "a: " << m_a << "  b: " << m_b << endl;
	}
public:
	int m_a;
	int m_b;
};


int main() {
	Test t1(1, 9);
	cout << "contain vitural size of Test: " << sizeof(Test) << endl;
	cout << "Run here!" << endl;
	return 0;
}


