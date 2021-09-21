#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// 容器 list 的使用方法 适合在任意位置快速插入移除元素
class Test {
public:
	Test(int a=0, int b=0) : m_a(a), m_b(b) {} // 该构造函数可以兼容无参、1个参数、2个参数的对象构造
private:
	int m_a;
	int m_b;
};

// 适用于基本类型
template <typename T>
void PrintList(list<T> &l) {
	// 这里有个关注点，开始写成 list<T>::iterater end_it; 时有问题。这里typename关键字可以大发神威啊。
	// 搞错了，是写错单词了... 尴尬
	// 不够我还是typedef强行让typename出场了一下
	typedef typename list<T>::iterator iterator;
	// typename 
	// list<T>::iterater end_it = l.end();
	iterator end_it = l.end();
	for (iterator it=l.begin(); it!=end_it; ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

// 来一个一元谓词
bool MyPredicate(int left) { // 元素小于5返回真，用在后面函数中的效果是取出列表中小于5的值
	return left < 6;
}


#if 0
#endif
void Playgrand1() {
	list<int> l1;
	for (int i=0; i<10; i++) {
		l1.push_back(i+1);
	}
	PrintList(l1);
	l1.remove(3);
	PrintList(l1);
	list<int>::iterator it = l1.begin();
	it++;
	it++;
	l1.insert(it, 3); // 把3插入回去
	PrintList(l1);
	// cout << "num: ";
	// int num;
	// cin >> num;
	l1.remove_if(MyPredicate);
	PrintList(l1);
}

void Playgrand2() {

}

void Playgrand3() {

}



int main() {
	Playgrand1();
	// Playgrand2();
	cout << "Run here!" << endl;
	return 0;
}

