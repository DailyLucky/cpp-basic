#include <iostream>

using namespace std;

int func1(int a, int b, int c=5);
int func1(int a, int b);
int main(void) {

	func1(1, 3); // 相当于传入参数1, 3, 5。最后一个参数用的默认参数
	func1(1, 5, 3);
	return 0;
}

int func1(int a, int b, int c) {
	cout << a << b << c <<endl;
	return 0;
}
int func1(int a, int b) {
	cout << a << b <<endl;
	return 0;
}