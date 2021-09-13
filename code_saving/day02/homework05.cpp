// 5. 定义一个Point类， 属性包括点的坐标，提供计算两点之间距离的方法  
//    定义一个圆类，包括其属性和半径 
//    创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果
#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
	void SetX(int x) {
		m_x = x;
	}
	void SetY(int y) {
		m_y = y;
	}
	void SetXY(int x, int y) {
		m_x = x;
		m_y = y;
	}
	int GetX() {
		return m_x;
	}
	int GetY() {
		return m_y;
	}
	double GetDistance(Point &other_point) {
		double distance = sqrt((other_point.GetX()-m_x)*(other_point.GetX()-m_x) +\
		                       (other_point.GetY()-m_y)*(other_point.GetY()-m_y));
		return distance;
	}

private:
	int m_x;
	int m_y;
};

class Circle {
public:
	void SetX(int x) {
		m_x = x;
	}
	void SetY(int y) {
		m_y = y;
	}	
	void SetR(int r) {
		m_r = r;
	}
	void SetXYR(int x=1, int y=1, int r=1) { // 带个默认参数，现学现卖，哈哈
		m_x = x;
		m_y = y;
		m_r = r;
	}
	int GetX() {
		return m_x;
	}
	int GetY() {
		return m_y;
	}
	int GetR() {
		return m_r;
	}
	int GetSquare(); // 获取面积的成员函数就先不写了，这里也用不到
	bool IsIntersect(Circle &other_circle) { // 相切与相离认为是不相交
		Point dot1, dot2;
		bool res = false;
		dot1.SetXY(m_x, m_y);
		dot2.SetXY(other_circle.GetX(), other_circle.GetY());
		if (dot1.GetDistance(dot2) < (m_r+other_circle.GetR())) {
			res = true;
		} else {
			res = false;
		}
		return res;
	}
private:
	int m_x; // 圆心坐标x
	int m_y; // 圆心坐标y
	int m_r; // 圆半径
};

int main() {
	Circle c1, c2;
	c1.SetXYR(0, 0, 3);
	c2.SetXYR(4, 0, 2);
	if (c1.IsIntersect(c2)) {
		cout << "c1 and c2 are intersect!" << endl;
	} else {
		cout << "c1 and c2 are not intersect!" << endl;
	}
	return 0;
}
