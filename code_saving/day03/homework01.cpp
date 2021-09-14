// 1.  构造函数的种类，
//     并举例说明。
// 无参构造
// 有参构造
// 拷贝构造
// 当我们不提供构造函数时，编译器会为我们提供一个空的构造函数
#include <iostream>

using namespace std;

class Test {
public:
	// 无参构造
	Test() {
		m_a = 0;
		m_b = 0;
	}
	// 带参构造
	Test(int a) {
		m_a = a;
		m_b = 1;
	}
	Test(int a, int b) {
		m_a = a;
		m_b = b;
	}
	// 拷贝构造
	Test(const Test &obj) {
		m_a = obj.m_a;
		m_b = obj.m_b;
	}
	// 析构函数
	~Test() {
		cout << "Destructor is executed!" << endl;
	}
private:
	int m_a;
	int m_b;
};

void objplay01();
void objplay02(Test obj);
Test objplay03();
// 演示构造函数的“舞台”
// 没有编写输出函数，直接debug看比较方便
void objplay01() {
	// 无参构造
	Test t1; 
	// 有参构造
	Test t2(9); // 括号法
	// 这两种有参构造在编写了拷贝构造函数后好像就不能用了，所以还是用括号法吧，我个人感觉括号法也最舒服。
	// Test t3 = (3, 100); // 等号法
	// Test t4 = Test(3, 100); // 直接调用构造函数法
	Test t5(200, 600);
	// 拷贝构造
	Test t6 = t1; // 等号法
	Test t7(t2); // 括号法
	Test t8 = Test(t7); // 直接调用构造函数法。这种写法构造函数要这样实现：Test(const Test &obj)，const必须要有。
	objplay02(t8);
	objplay03(); // 没有来接这个匿名对象，直接析构掉
	t8 = objplay03(); // 在将值赋给t8后析构掉
	Test t100 = objplay03(); // 只有这种才能接住这个匿名对象
	cout << "objplay01() end!" << endl;
}

void objplay02(Test t9) { // 实参到形参的拷贝构造
	cout << "objplay02() end!" << endl;
}

Test objplay03() { // 返回变量的拷贝构造
	Test t10(10, 10);
	cout << "objplay03() end!" << endl;
	return t10;
}

int main() {
	objplay01();
	return 0;
}