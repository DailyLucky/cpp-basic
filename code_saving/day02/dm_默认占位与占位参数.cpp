#include <iostream>

using namespace std;

// int func1(int a, int b, int = 0) {
// 	return 0;
// }
int func1(int a, int = 0, int b = 1) {
	return a + b;
}
int main(void) {

	cout << func1(1, 3) << endl; // 相当于传入参数1, 3, 5。最后一个参数用的默认参数
	cout << func1(1, 5, 3) << endl;
	return 0;
}
