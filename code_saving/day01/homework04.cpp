#include <iostream>

using namespace std;
int main(void) {
	int a = 10;
	int b = 20;
	(1 < 2? a: b) = 100; // 正确。C++对相对于C语言将三目运算符进行了加强
	//(1 < 2? 10: 20) = 100; // 错误。不合法的左值
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	return 0;
}