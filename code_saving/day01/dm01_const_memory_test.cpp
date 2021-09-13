#include <iostream>

using namespace std;
int main(void) {
	int a = 10;
	const int c = 20;
	int b = 20;
	int *d = (int *)&c;
	cout << "&a: " << &a << endl;
	cout << "&b: " << &b << endl;

	return 0;
}
/*
	int a = 10;
	const int c = 20;
	int b = 20;
	int *d = (int *)c;
&a: 0x61fe0c
&b: 0x61fe08
// 没有&c，变量a与b的内存分配是连续的。
	int a = 10;
	const int c = 20;
	int b = 20;
	int *d = (int *)&c;
&a: 0x61fe14
&b: 0x61fe0c
// 有&c，进行了内存的分配。此时变量a与b的内存分配不连续。
*/