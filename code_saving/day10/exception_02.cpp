/*
    异常测试
	捉不住异常时自己来一个最后一道防线，这里需要引入头文件“exception”
*/

#include <iostream>
#include <exception>
using namespace std;


void test() {
	cout << "First Sentance"  << endl;
	throw "you can't catch the exception, hahaha!";
	cout << "I'll never be executed";
}

void Playgrand1() {
	try {
		test();
	} catch (int e) {
		cout << "I catch it!" << endl;
	} 
	// catch (...) {
	// 	cout << "I can catch everything" << endl;
	// }
}

void MyTerminate() {
	cout << "Hello, tang\n" << "I'm the last defence" << endl;
}

int main() {
	set_terminate(MyTerminate);
	Playgrand1();
	cout << "Run here!" << endl;
	return 0;
}