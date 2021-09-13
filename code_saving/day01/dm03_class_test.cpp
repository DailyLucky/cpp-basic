#include <iostream>

// 输入圆的半径，求圆的面积
using namespace std;

class Circle {
public:
	double radius; // 成员变量：半径
	
public:
	void SetRadius(double r) {
		radius = r;
	}

	double GetRadius(void) {
		return radius;
	}

	double GetArea(void) {
		return (3.14 * radius * radius); //pi*r*r
	}
};

int main(void) {
	Circle c1;
	double r = 0.0;
	cout << "please enter c1's radius: ";
	cin >> r;
	c1.SetRadius(r);
	cout << "The radius is " << c1.GetRadius() << endl;
	cout << "It's area is " << c1.GetArea() << endl;
	return 0;
}