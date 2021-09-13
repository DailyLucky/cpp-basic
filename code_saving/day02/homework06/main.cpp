// 6. 设计并测试一个名为Rect的矩形类，其属性为矩形的左下角与
//    右下角两个坐标，根据坐标能计算出矩形的面积
// 我刚好用这道题练习一下将类的实现写在别的文件的写法
#include <iostream>
#include "Rect.h"

using namespace std;

int main() {
	Rect r1;
	r1.SetAllPoint(1, 0, 20, 2);
	cout << "r1's area is " << r1.GetArea() << endl;
	return 0;
}