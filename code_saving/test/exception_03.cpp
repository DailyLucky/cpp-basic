/*
    异常测试
	打包个异常类
*/

#include <iostream>
#include <exception>
using namespace std;


	class eSize {
	public:
		eSize(int _err_num = -1) {
			err_num = _err_num;
		}
		virtual void printErr() = 0;
	protected:
		int err_num;
	};
	class eNegative : public eSize {
	public:
		eNegative(int _err_num) : eSize(_err_num) { };
		virtual void printErr() {
			cout << "Index: " << err_num <<  "  eNegative exception!" << endl;
		}
	};
	class eZero : public eSize {
	public:
		eZero(int _err_num) : eSize(_err_num) { };
		virtual void printErr() {
			cout << "Index: " << err_num <<  "  eZero exception!" << endl;
		}
	};
	class eTooBig : public eSize {
	public:
		eTooBig(int _err_num) : eSize(_err_num) { };
		virtual void printErr() {
			cout << "Index: " << err_num <<  "  eTooBig exception!" << endl;
		}
	};
	class eTooSmall : public eSize {
	public:
		eTooSmall(int _err_num) : eSize(_err_num) { };
		virtual void printErr() {
			cout << "Index: " << err_num <<  "  eTooSmall exception!" << endl;
		}
	};

class MyArray {
public:

	MyArray(int index) {
		// 抛异常逻辑
		if (index < 0) {
			throw eNegative(index);
		} else if (index == 0) {
			throw eZero(index);
		} else if (index < 10) {
			throw eTooSmall(index);
		} else if (index > 1000) {
			throw eTooBig(index);
		}
		len = index;
		space = new int[len];
	}

	MyArray(const MyArray &arr) { // 拷贝构造
		if (arr.space != NULL) {
			len = arr.len;
			space = new int[len];	
		} else {
			len = 0;
			space = NULL;
		}
	}
	~MyArray() {
		if (space != NULL) {
			len = 0;
			delete [] space;
			space = NULL;
		}
	}

	// 操作符重载
	int& operator[](int index) {
		return space[index];
	}
private:
	int len;
	int *space;
};

void Playgrand1() {
	try {
		MyArray arr0(20);
		// MyArray arr1(-7);
		// MyArray arr2(0);
		// MyArray arr3(1005);
		// MyArray arr4(5);
	} catch (eSize &e) {
		e.printErr();
	} 
	catch (...) {
		cout << "I can catch everything" << endl;
	}
}


int main() {
	// Playgrand1();
	// 成员大小的测试结果很出乎意料啊，得找个时间研究一下。
	cout << "size of int *: " << sizeof(int *) << endl;
	cout << "size of char *: " << sizeof(char *) << endl;
	cout << "size of MyArray: "<< sizeof(MyArray) << endl;
	cout << "size of eSize: " << sizeof(eSize) << endl;
	cout << "size of member function pointer: " << sizeof(MyArray::operator[]) << endl;
	cout << "size of member function pointer: " << sizeof(eSize::printErr) << endl;
	cout << "Run here!" << endl;
	return 0;
}