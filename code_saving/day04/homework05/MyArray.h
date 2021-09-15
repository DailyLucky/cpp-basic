#pragma once
// 5. 课程中的自定义数组，实现<<操作符 实现取值操作符[]
//    array[i] = 10;
// int operator[](int val);
//    cout <<array<<endl;
//    cout <<array[i] <<endl;
//    ==
//    !=
//    array1 == array2
//    array1 != array2
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class MyArray
{
public:
	//无参构造函数
	MyArray();

	//在给数组初始化的时候，开辟多少个元素空间
	MyArray(int len=0);

	//拷贝构造函数
	MyArray(const MyArray& another);

	int getLen();

	//index 代表要赋值的数组的下标, data 数据
	void setData(int index, int data);

	int getData(int index);

	// 操作符重载函数	
	int& operator[](int index);
	friend ostream& operator<<(ostream &out, MyArray &obj);
	bool operator==(MyArray &obj);
	bool operator!=(MyArray &obj);

	~MyArray();

private:
	int length; //数组目前的元素个数
	int *space; //space 是在堆上开辟数组空间的首元素地址。
};

