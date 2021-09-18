// 和结构体一样，当没有成员变量时，类的大小为1。因为类作为内存分配模具总是要有具体的大小的。
#include <iostream>

using namespace std;
class Test {
public:
	void func();
	void func2();
private:
	// int m_a;
	// int m_b;
};

struct Test2 {

};

int main() {
	Test t1;
	Test2 t2;
	cout << sizeof(Test) << endl;
	cout << sizeof(Test2) << endl;
	cout << "Run here!" << endl;
	return 0;
}


