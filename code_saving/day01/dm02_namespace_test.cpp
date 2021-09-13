#include <iostream>

namespace A {
	int value = 10;
	using namespace std;
}

namespace B {
	int value = 20;
	namespace C {
		int value = B::value + 1;
	}
}

using namespace A;

int main(void) {
	int a = 0;
	cout << "Please enter an interger variable: ";
	cin >> a;
	cout << "you entered " << a << endl << B::C::value << endl;

	return 0;
}