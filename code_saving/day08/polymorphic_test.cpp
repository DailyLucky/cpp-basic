#include <iostream>

using namespace std;

class Shape {
public:
	virtual void ShowProperty() = 0; // 展示图形具有的属性
	virtual double GetArea() = 0; // 获取图形的面积
	virtual ~Shape() { }
};

class Circle : public Shape {
public:
	Circle(int _radius) : radius(_radius) { }

	~Circle() {
		cout << "Circle's destructor was called." << endl;
	}

	void ShowProperty() {
		cout << "Circle ==> radius: " << radius << endl;
	}

	double GetArea() {
		return 3.14*radius*radius;
	}

private:
	double radius;
};

class Rectangle : public Shape {
public:
	Rectangle(double _length, double _width) : length(_length), width(_width) { }

	~Rectangle() {
		cout << "Rectangle's destructor was called." << endl;
	}

	void ShowProperty() {
		cout << "Rectangle ==> length: " << length << "  width: " << width << endl;
	}

	double GetArea() {
		return length*width;
	}

private:
	double length;
	double width;
};

int main() {
	Shape *pArr[2] = {NULL};

	double radius = 0.0;
	cout << "Creating Circle..." << endl;
	cout << "Please enter the radius: ";
	cin >> radius;
	pArr[0] = new Circle(radius);

	double length = 0.0, width = 0.0;
	cout << "Creating Rectangle..." << endl;
	cout << "Please enter the length: ";
	cin >> length;
	cout << "Please enter the width: ";
	cin >> width;
	pArr[1] = new Rectangle(length, width);

	for (int i=0; i<2; i++) {
		pArr[i]->ShowProperty();
		cout << "The area is " << pArr[i]->GetArea() << endl;
		delete pArr[i];
	}

	cout << "Run here!" << endl;
	return 0;
}

