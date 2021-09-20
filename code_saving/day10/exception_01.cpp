/*
    异常测试
*/

#include <iostream>

using namespace std;

int MyDivide(int x, int y) {
	if (y == 0) {
		throw x;
	}
	return (x / y);
}

int IsolateFunc() {
	int a = 0;
	MyDivide(30, 0); // 这里如果先出现异常会把后面的内容通通短路掉
	throw "Unknown"; // 抛出一个未知异常测试一下
	return a;
}

void Playgrand1() {
	try {
		MyDivide(34, 1);
		cout << "Hello, exception" << endl;
	} catch (int e) {
		cout << e << " divided by 0, error!" << endl;
	} catch (...) {
		cout << "Unknown error!" << endl;
	}
}
// 抛异常和接异常的函数中间即使间隔有其它函数也是OK的。
void Playgrand2() {
	try {
		IsolateFunc();
		cout << "Hello, exception" << endl;
	} catch (int e) {
		cout << e << " divided by 0, error!" << endl;
	} catch (...) {
		cout << "Unknown error!" << endl;
	}
}
int main() {
	Playgrand2();
	cout << "Run here!" << endl;
	return 0;
}