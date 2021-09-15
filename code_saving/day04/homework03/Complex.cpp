#include "Complex.h"

using namespace std;
// 3. 实现一个复数类的+=，-=,前++，后++，前--，后--，<<, >>，等操作符重载


Complex Complex::operator+(const Complex &obj) {
    Complex temp(Real+obj.Real, Image+obj.Image);
    return temp;
}

Complex Complex::operator-(const Complex &obj) {
    Complex temp(Real-obj.Real, Image-obj.Image);
    return temp;
}

Complex& Complex::operator+=(const Complex &obj) {
    Real += obj.Real;
    Image += obj.Image;
    return *this;
}

Complex& Complex::operator-=(const Complex &obj) {
    Real -= obj.Real;
    Image -= obj.Image;
    return *this;
}

Complex& Complex::operator++() {
    Real++;
    Image++;
    return *this;
}
Complex Complex::operator++(int) {
    Complex temp(Real, Image);
    Real++;
    Image++;
    return temp;
}

Complex& Complex::operator--() {
    Real--;
    Image--;
    return *this;
}
Complex Complex::operator--(int) {
    Complex temp(Real, Image);
    Real--;
    Image--;
    return temp;
}

// 友元函数实现<<、>>的重载
ostream& operator<<(ostream &out, const Complex &obj) {
    out << "(" << obj.Real <<" + " << obj.Image << "i)" << endl;
    return out;
}

istream& operator>>(istream &in, Complex &obj) {
    cout << "Real: ";
    in >> obj.Real;
    cout << "Image: ";
    in >> obj.Image;
    cout << endl;
    return in;
}