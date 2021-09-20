#include <iostream>

using namespace std;

void Playgrand1();

class Test {
public:
	Test(int a=0, int b=0) : m_a(a), m_b(b) {} // 该构造函数可以兼容无参、1个参数、2个参数的对象构造
	~Test() {
		cout << "~Test()..." << endl;
	}
private:
	int m_a;
	int m_b;
};

// 局部变量不能返回引用
Test func() {
	Test temp(5, 5);
	return temp;
}

int main() {
	Playgrand1();
	cout << "Run here!" << endl;
	return 0;
}

void Playgrand1() {
	// Test &ref1 = func(); // 这种写法通不过编译，不用考虑这种接返回值的情况，我想多了。
	cout << "--------" << endl;
	Test t1 = func();
	cout<< "Testing..." << endl;
}