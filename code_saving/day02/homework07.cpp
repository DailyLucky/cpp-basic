// 7. 定义一个Tree类，有成员ages（树龄）， 成员函数grow（int years）对ages加上
//    years，age（）显示trees对象的ages值。
#include <iostream>

using namespace std;

class Tree {
public:
	void setAge(int _age) {
		ages = _age;
	}
	// 题目说的那两个成员函数的实现写在后面的
	void grow(int years);
	int age();

private:
	int ages;
};

int main() {
	Tree t1;
	cout << t1.age() << endl;
	t1.setAge(10);
	t1.grow(89);
	cout << t1.age() << endl;
	return 0;
}

void Tree::grow(int years) {
	ages += years;
}

int Tree::age() {
	return ages;
}