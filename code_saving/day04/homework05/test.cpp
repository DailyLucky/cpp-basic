#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "MyArray.h"

using namespace std;

int main(void)
{
	MyArray array1(10); //调用MyArray 有参数构造函数
	//设置一个数组的所有元素
	for (int i = 0; i< array1.getLen(); i++) {
		array1[i] = i;
	}
	cout << " -------- " << endl;
	//遍历一个数组的所有元素

	// cout << " ---一下是拷贝构造函数测试----" << endl;
	MyArray array2 = array1; //调用了array2的拷贝构造函数
	cout << array1 << endl << array2 << endl;
    if (array2 == array1) {
        cout << "equl!" << endl;
    } else {
        cout << "unequl!" << endl;
    }
    if (array2 != array1) {
        cout << "unequl!" << endl;
    } else {
        cout << "equl!" << endl;
    }

	return 0;
}