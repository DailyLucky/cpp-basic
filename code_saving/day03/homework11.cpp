// 11. static修饰的类成员变量和成员函数的特点。
//     如何初始化一个static修饰的成员变量。
//     如何使用一个static修饰的成员函数？
#include <iostream>

using namespace std;

class Test 
{ 
public:
	Test() : m_a(0), m_b(0) {} // 列表初始化，现学现卖哈。
	Test(int a, int b) : m_a(a), m_b(b) {}
	static void AddC() {
		s_c++;
	}
	int GetC() {
		return s_c;
	}
private:
	int m_a;
	int m_b;
	static int s_c; 
	
};
//int Test::s_c = 100;  // 初始化Test类的静态变量的写法

int main(void)
{
	Test t1(2, 5), t2;
	t1.AddC();
	cout << "C is " << t2.GetC() << endl;
	t2.AddC();
	cout << "C is " << t2.GetC() << endl;
	Test::AddC(); // 直接通过类名调用
	cout << "C is " << t1.GetC() << endl;
	return 0;
}