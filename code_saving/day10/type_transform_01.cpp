/*
    C风格转换转换语法：
    TYPE a = (TYPE)b;

    C++风格转换转换语法：
    TYPE a = static_cast<TYPE>(b);
    将b静态转换为a
    C++提供的4种转换方式：
    1. static_cast         静态转换
    2. reinterpreter_cast  重新解释
       // 以上两种就能完全替代C风格的类型转换
    3. dynamic_cast        动态转换，通常用语基类与派生类之间的转换
    4. const_cast          常量转换，取消只读属性

*/

#include <iostream>

using namespace std;

int main() {
    int a = 10;
    double b = static_cast<double>(a);
    cout << "a: " << a << "  b: " << b << endl;

    double c = 15.999;
    int d = static_cast<int>(c);
    cout << "c: " << c << "  d: " << d << endl;

	cout << "Run here!" << endl;
	return 0;
}