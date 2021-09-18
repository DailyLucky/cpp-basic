// 6. 何为面向抽象层编程？意义何在？
/*
面向抽象层编程就是面向接口编程。接口是定义好的一组函数原型，相当于协议。具体的实现交给子类去实现就行。
实现了对编程的分层处理。
 */
#include <iostream>

using namespace std;

//抽象类1
class Interface1
{
public:
	//纯虚函数
	virtual void func(int a, int b) = 0;
	virtual void func2(int a) = 0;
};

class Interface2
{
public:
	virtual void func(int a, int b) = 0;
};

//当纯虚函数在多继承中出现了重复， 那么在子类中只要重新重写一次就可以了
class Child : public Interface1, public Interface2
{
public:
	virtual void func(int a, int b)
	{
		cout << "a = " << a << "b = " << b << endl;
	}
	virtual void func2(int a)
	{
		cout << "func2 ()" << endl;
	}
	// 这里继承了两个抽象类，所有有两个虚函数表。sizeof(Child)的值为16，如果只继承Interface1，sizeof(Child)的值为8。
};

int main(void)
{
	Child c;
	cout << "size of Child is " << sizeof(Child) << endl;
	c.func(10, 20);

	Interface1 *if1 = new Child;
	if1->func(10, 20);
	if1->func2(10);

	Interface2 *if2 = new Child;
	if2->func(10,20);

	
	return 0;
}