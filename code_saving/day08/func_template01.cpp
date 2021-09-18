#include <iostream>

using namespace std;

template <typename T>
void MySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 10, b = 20;
    char c = 'A', d = 'a';

    MySwap<int>(a, b);
    cout << "a: " << a << "  b: " << b << endl;

    MySwap(c, d);
    cout << "c: " << c << "  d: " << d << endl;

	cout << "Run here!" << endl;
	return 0;
}