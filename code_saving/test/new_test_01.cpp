/*
    dynamic_cast、reinterpret_cast测试
*/

#include <iostream>

using namespace std;

void Playgrand1() {
	// void *operator new[](std::size_t)
	// 下面这条语句可以这样解读 new int[5] [4]
	// 即new了一个int[5]类型的数组，数组元素个数为4
	int (*p)[5] = new int[4][5];
	int *p2 = new int[10];
	cout << "Value of p: " << p << endl;
	cout << "Value of p+1: " << p+1 << endl;
	cout << "Value of p2: " << p2 << endl;
	cout << "Value of p2+1: " << p2+1 << endl;
	delete []p;
	delete []p2;
}

int main() {
	Playgrand1();
	cout << "Run here!" << endl;
	return 0;
}