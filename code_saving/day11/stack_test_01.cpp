#include <iostream>
#include <stack>
#include <deque>
#include <vector>
using namespace std;


class Test {
public:
	Test(int a=0, int b=0) : m_a(a), m_b(b) {} // 该构造函数可以兼容无参、1个参数、2个参数的对象构造
private:
	int m_a;
	int m_b;
};

// 适用于基本类型
template <typename T>
void PrintStack(stack<T> &stq) {
	stack<T> temp = stq;
	int len = temp.size();
	for (int i=0; i<len; ++i) {
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;
}

#if 0

void Playgrand1() {
	// 初始化方法
	stack<int> s1;
	for (int i=0; i<5; i++) {
		s1.push(i);
	}
	PrintStack(s1);
}

void Playgrand2() {
	// size()、 empty()
	// 突然发现好像可以把双端队列入栈
	deque<int> d1;
	for (int i=0; i<5; i++) {
		d1.push_back(i+1);
	}
	stack<int> s1(d1);
	PrintStack(s1);
	while (!s1.empty()) {
		cout << "stack size: " << s1.size() << " pop value:" << s1.top() << endl;
		s1.pop();
	}
	// cout << endl;
}
#endif
void Playgrand3() {

}



int main() {
	// Playgrand1();
	// Playgrand2();
	cout << "Run here!" << endl;
	return 0;
}

