#include <iostream>
#include <deque>
using namespace std;

// 双端队列deque和vector的操作比较类似，只不过deque是两端开口而已
// 适合在头尾添加移除元素。使用方法与 vector 类似
class Test {
public:
	Test(int a=0, int b=0) : m_a(a), m_b(b) {} // 该构造函数可以兼容无参、1个参数、2个参数的对象构造
private:
	int m_a;
	int m_b;
};

// 适用于基本类型
template <typename T>
void PrintDeque(deque<T> &deq) {
	int len = deq.size();
	for (int i=0; i<len; ++i) {
		cout << deq[i] << " ";
	}
	cout << endl;
}

#if 0

void Playgrand1() {
	// 初始化方法
	deque<int> d1; // 无参构造
	deque<int> d2(4);
	deque<int> d3(4, 66);
	deque<int> d4(d3);
	deque<int> d5(d3.begin(), d3.end()-2);
	PrintDeque(d1);
	PrintDeque(d2);
	PrintDeque(d3);
	PrintDeque(d4);
	PrintDeque(d5);
}

void Playgrand2() {
	// 插入，修改
	deque<int> d1;
	for (int i=0; i<5; i++) {
		d1.push_front(i);
		d1.push_back(i+1);
	}
	PrintDeque(d1);
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

