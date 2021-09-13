#include <iostream>

using namespace std;

// 默认参数函数声明
// int func1(int a, int b=0, int c); // error。从第一个赋了默认值的参数开始，右侧的参数都必须有默认值
int func1(int a, int b=2, int c=5);
int main(void) {
	// func1(); // a是没有赋默认参数的，所以该调用方法错误
	func1(1); // 相当于传入参数1, 2, 5。后两个用的默认参数
	func1(1, 3); // 相当于传入参数1, 3, 5。最后一个参数用的默认参数
	func1(1, 5, 3);
	return 0;
}

int func1(int a, int b, int c) {
	cout << a << b << c <<endl;
	return 0;
}