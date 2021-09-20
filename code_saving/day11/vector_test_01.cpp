#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // 输出流控制需要引用这个头文件

using namespace std;

// 测试案例。这么写还挺好，做完测试可以直接把 #endif 往下面移动下就可以屏蔽最新的测试代码，nice。

class Teacher {
public:
	Teacher(string _name = "unknown", int _age = 20) {
		name = _name;
		age = _age;
	}
	Teacher(const Teacher &t) {
		name = t.name;
		age = t.age;
	}
	void PrintTeacher() {
		cout << "name: " << name << "  age: " << age << endl;
	}
private:
	string name;
	int age;
};

// 适用于基本类型
template <typename T>
void PrintVector(vector<T> &v) {
	int len = v.size();
	for (int i=0; i<len; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

#if 0
void Playgrand1() {
	vector<int> v1;
	cout << "v1 length: " << v1.size() << endl;
	for (int i=0; i<5; ++i) {
		v1.push_back(i+1);
	}
	cout << "v1 length: " << v1.size() << endl;
	// for (int i=0; i<7; ++i) { // 由于在上面的循环只在尾部插入了5个元素，这里多遍历两次会有垃圾值
	// 	cout << v1[i] << " ";
	// }
	cout << endl;

	// 类模板就是功能强大，啥都能装进去。
	vector<Teacher> teacher;
	teacher.push_back(Teacher("tang", 22));
	teacher.push_back(Teacher("wang", 30));
	for (vector<Teacher>::iterator it=teacher.begin(); it!=teacher.end(); ++it) {
		it->PrintTeacher();
	}
}

void Playgrand2() {
	// vector<int> v1(10);
	// cout << "v1 length: " << v1.size() << endl;
	// for (int i=0; i<5; ++i) {
	// 	v1.push_back(i+1);
	// }
	// cout << "v1 length: " << v1.size() << endl;
	// for (vector<int>::iterator it=v1.begin(); it!=v1.end(); ++it) { // 迭代器正向遍历
	// 	cout << *it << " ";
	// }
	// cout << endl;
	// for (vector<int>::reverse_iterator it=v1.rbegin(); it!=v1.rend(); ++it) { // 迭代器反向遍历
	// 	cout << *it << " ";
	// }
	vector<double> v2(5, 3.1415926);
	// 数组方式遍历
	// ! 如果以数组方式进行操作，首先要保证容器已经分配好了内存才是安全的。
	for (int i=0; i<5; i++) { 
		cout << setprecision(8) << v2[i] << " ";
	}
	cout << endl;
	v2.push_back(4.01);
	v2.push_back(9.999);
	vector<double> v3(v2);
	for (vector<double>::iterator it=v3.begin(); it!=v3.end(); ++it) { // 迭代器正向遍历
		cout << *it << " ";
	}
	cout << endl;

}

void Playgrand3() {
	vector<int> v1;
	for (int i=0; i<10; i++) {
		v1.push_back(i+1);
	}
	for (vector<int>::iterator it=v1.begin(); it!=v1.end(); ++it) { // 迭代器正向遍历
		cout << *it << " ";
	}
	cout << endl;
	vector<int> v2(v1);
	v2.assign(2, 0);
	for (vector<int>::iterator it=v2.begin(); it!=v2.end(); ++it) { // 迭代器正向遍历
		cout << *it << " ";
	}
	cout << endl;
	v2 = v1;
	for (int i=0; i<v2.size(); i++) { // 数组方式遍历
		cout << v2[i] << " ";
	}
	cout << endl;
	v2 = vector<int>(10, 99);
	v2.swap(v1);
	for (int i=0; i<v1.size(); i++) { // 数组方式遍历
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i=0; i<v2.size(); i++) { // 数组方式遍历
		cout << v2[i] << " ";
	}
	cout << endl;
}

void Playgrand4() {
	// push_back() and pop_back()
	vector<int> v1;
	if (v1.empty()) {
		cout << "vector v1 is empty" << endl;
	}
	for (int i=0; i<3; i++) {
		v1.push_back(i+1);
		
	}
	while (v1.size() != 0) {
		cout << "what you will pop is " << v1.back() << endl;
		v1.pop_back();
	}
	cout << endl;
}

void Playgrand5() {
	
	vector<int> v1(10, 99);
	cout << v1.capacity() << endl;
	for (int i=0; i<v1.size(); ++i) {
		v1[i] = i;
	}
	cout << "The first element is " << v1.front() << endl;
	srand(10*time(NULL)); // 要想有更好的随机效果需要生成一个随机数种子
	int rand_index = rand() % v1.size();
	cout << "The " << rand_index << " element is " << v1.at(rand_index) << endl;
	cout << "The last element is " << v1.back() << endl;
}

void Playgrand6() {
	// insert() and erase()
	vector<int> v1;
	for (int i=0; i<5; i++) {
		v1.push_back(i+1);
	}
	for (vector<int>::iterator it=v1.begin(); it!=v1.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	v1.insert(v1.begin(), 10);
	PrintVector(v1);
	vector<int>::iterator it = v1.begin();
	v1.insert(it+2, 100);
	PrintVector(v1);
	v1.insert(it+3, 5, -1); // 在第3个位置前(从0开始算)插入5个-1
	PrintVector(v1);
	v1.erase(it+3);
	PrintVector(v1);
	v1.erase(it, it+v1.size()); // 删除所有
	PrintVector(v1);
}

void Playgrand7() {
	// 将一个容器插入到另一个容器
	vector<int> v1(4, 0);
	vector<int> v2(5, 9);
	PrintVector(v1);
	PrintVector(v2);
	vector<int>::iterator it1, it2, it3;
	it1 = v1.begin() + 2;
	it2 = v2.begin();
	it3 = v2.end();
	v1.insert(it1, it2, it3);
	PrintVector(v1);
}
#endif


void Playgrandn() {

}

int main() {
	// Playgrand1();
	// Playgrand2();
	// Playgrand3();
	// Playgrand4();
	// Playgrand5();
	// Playgrand6();
	// Playgrand7();

	cout << "Run here!" << endl;
	return 0;
}