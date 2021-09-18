#include <iostream>

using namespace std;

// 定义一个复数模板类
template <class T>
class Complex {
public:
    Complex(T a, T b) : Real(a), Image(b) { }
    ~Complex() { };
    void PrintComplex() {
        cout << Real << " + " << Image << "i" << endl;
    }
    Complex operator+(const Complex &obj) {
        return Complex(Real+obj.Real, Image+obj.Image);
    }
    Complex operator-(const Complex &obj) {
        return Complex(Real-obj.Real, Image-obj.Image);
    }
    // cout << c1 << endl
    friend ostream& operator<<(ostream &out, Complex &obj) {
        out << obj.Real << " + " << obj.Image << "i" ;
        return out;
    }
    friend Complex MySub(Complex &left, Complex &right) {
        return Complex(left.Real-right.Real, left.Image-right.Image);
    }
private:
    T Real;
    T Image;
};




int main() {
    Complex<int> c1(45, 15), c2(9, -37);
    Complex<int> c3 = MySub(c1, c2);
    cout << c3 << endl;
	cout << "Run here!" << endl;
	return 0;
}