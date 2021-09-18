#include <iostream>

using namespace std;
// 类前置声明
// 话说我好像被写两行的模板声明迷惑了
// template <class T> class Complex; 这样写一看就是不能分割的啊

// 还是有些绕，先记住结论吧
template <class T>
class Complex;

// 友元函数前置声明
template <class T>
ostream& operator<<(ostream &out, Complex<T> &obj);

template <class T>
Complex<T> MySub(Complex<T> &left, Complex<T> &right);
// 定义一个复数模板类
template <class T>
class Complex {
public:
    Complex(T a, T b);
    ~Complex();
    void PrintComplex();
    Complex operator+(const Complex &obj);
    Complex operator-(const Complex &obj);
    // cout << c1 << endl
    friend ostream& operator<<<T>(ostream &out, Complex &obj);
    friend Complex MySub<T>(Complex &left, Complex &right);
private:
    T Real;
    T Image;
};
template <class T>
Complex<T>::Complex(T a, T b) : Real(a), Image(b) { }

template <class T>
Complex<T>::~Complex() { };

template <class T>
void Complex<T>::PrintComplex() {
    cout << Real << " + " << Image << "i" << endl;
}
template <class T>
Complex<T> Complex<T>::operator+(const Complex &obj) {
    return Complex(Real+obj.Real, Image+obj.Image);
}

template <class T>
Complex<T> Complex<T>::operator-(const Complex &obj) {
    return Complex(Real-obj.Real, Image-obj.Image);
}
// // cout << c1 << endl
template <class T>
ostream& operator<<(ostream &out, Complex<T> &obj) {
    out << obj.Real << " + " << obj.Image << "i" ;
    return out;
}
template <class T>
Complex<T> MySub(Complex<T> &left, Complex<T> &right) {
    return Complex<T>(left.Real-right.Real, left.Image-right.Image);
}


int main() {
    Complex<int> c1(45, 15), c2(9, -37);
    Complex<int> c3 = MySub(c1, c2);
    cout << c3 << endl;
	cout << "Run here!" << endl;
	return 0;
}