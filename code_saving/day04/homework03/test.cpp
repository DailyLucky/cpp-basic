#include <iostream>
#include "Complex.h"

using namespace std;

// 暂时定义了一个Complex类的友元函数来进行打印
void PrintComplex(const Complex &obj) { 
    printf("(%d+%di)\n", obj.Real, obj.Image);
}

int main() {
    Complex c1(1,0), c2(0,1);
    Complex c3 = c1 + c2;
    c2 = c3;
    cin >> c1 >> c2 >> c3;
    cout << c1 << c2 << c3;

    cout << "Run here!" << endl;
	return 0;
}