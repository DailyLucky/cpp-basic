/*
    异常测试
	使用C++提供的标准异常库
*/

#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;


void Playgrand1() {
	try {
		int arr[10];
		for (int i=0; i<12; i++) {
			if (i >= 10) {
				throw out_of_range("Array out of bounds!");
			}
			arr[i] = 0;
		}
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
}


int main() {
	Playgrand1();
	cout << "Run here!" << endl;
	return 0;
}
