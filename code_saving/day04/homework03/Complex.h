#pragma once
#include <iostream>
// 3. 实现一个复数类的+=，-=,前++，后++，前--，后--，<<, >>，等操作符重载
class Complex {
public:
    // 构造函数，析构函数
	Complex(int a=0, int b=0) : Real(a), Image(b) {} // 该构造函数可以兼容无参、1个参数、2个参数的对象构造
    ~Complex() {}
    // 进行一波操作符重载
    Complex operator+(const Complex &obj);
    Complex operator-(const Complex &obj);
    Complex& operator+=(const Complex &obj);
    Complex& operator-=(const Complex &obj);
    Complex& operator++(); // 前置++
    Complex operator++(int); // 后置++
    Complex& operator--(); // 前置--
    Complex operator--(int); // 后置--

    friend void PrintComplex(const Complex &obj);
    friend std::ostream& operator<<(std::ostream &out, const Complex &obj);
    friend std::istream& operator>>(std::istream &in, Complex &obj);
private:
	int Real;
	int Image;
};