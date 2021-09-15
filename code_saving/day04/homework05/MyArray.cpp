#include "MyArray.h"


MyArray::MyArray()
{
	this->space = NULL;
	this->length = 0;
}

MyArray::MyArray(int len)
{
	if (len <= 0) {
		this->length = 0;
		return;
	}
	else {
		this->length = len;
		this->space = new int[this->length]; //在堆上开辟了 长度为length的连续int空间
		cout << "Construct MyArray::MyArray(int len) has called!" << endl;
	}
}


//拷贝构造函数
MyArray::MyArray(const MyArray& another)
{
	if (another.length >= 0) {
		this->length = another.length;
		this->space = new int[this->length];

		for (int i = 0; i < this->length; i++) {
			this->space[i] = another.space[i];
		}

		cout << "Construct MyArray::MyArray(const MyArray& another) has called!" << endl;
	}
}


MyArray::~MyArray()
{
	if (this->space != NULL) {
		//此时space 有空间
		delete [] this->space;
		this->length = 0;
		this->space = NULL;
		cout << "MyArray::~MyArray() has called!" << endl;
	}
}

int MyArray::getLen()
{
	return this->length;
}


//index 代表要赋值的数组的下标, data 数据
void MyArray::setData(int index, int data)
{
	if (this->space != NULL) {
		this->space[index] = data;
	}
}

int  MyArray::getData(int index)
{
	return this->space[index];
}
// a[i] = 0;
int& MyArray::operator[](int index) {
	return space[index];
}

bool MyArray::operator==(MyArray &obj) {
	if (length != obj.length) {
		return false;
	} else {
		for (int i=0; i<length; i++) {
			if ((*this)[i] != obj[i]) {
				return false;
			}
		}
	}
	return true;
}
bool MyArray::operator!=(MyArray &obj) {
	return !(*this==obj);
}

ostream& operator<<(ostream &out, MyArray &obj) {
	out << "I love cpp!" << endl;
	for (int i=0; i<obj.length; i++) {
		out << obj[i] << " ";
	}
	return out;
}