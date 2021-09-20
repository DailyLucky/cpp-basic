/*
    异常测试
	使用标准库异常进行三角形面积计算中非法参数的处理
*/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>

using namespace std;



double CalcuArea(double a, double b, double c) {
	if (a<=0 || b<=0 || c<=0) { // 边长应为非负数
		throw invalid_argument("Exist invalid argument(s)!");
	}
	if ((a+b<=c) || (a+c<=b) || (b+c<=a)) {
		throw invalid_argument("Don't meet two sides' sum more than the third side!");
	}
	double p = (a + b + c) / 2;
	return (sqrt(p * (p-a) * (p-b) * (p-c))); // 海伦公式
}

void Playgrand1() {
	double a, b, c;
	cout << "Please enter the triangle's side lenght: ";
	cin >> a >> b >> c;
	try {
		cout << "The square is " << CalcuArea(a, b, c) << endl;
	} catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}

int main() {
	Playgrand1();
	cout << "Run here!" << endl;
	return 0;
}
