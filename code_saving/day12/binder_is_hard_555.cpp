#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;

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
	Teacher& operator=(Teacher &t) {
		name = t.name;
		age = t.age;
		return *this;
	}
	bool operator==(const Teacher &t) {
		return (name==t.name) && (age==t.age);
	}
	friend ostream& operator<<(ostream &out, const Teacher &t) {
		out << t.name << "  " << t.age << endl;
		return out;
	}
private:
	string name;
	int age;
};

template <typename _Type>
void PrintVector(vector<_Type> &v) {
	typedef typename vector<_Type>::iterator _Type_iterator;
	_Type_iterator it_end = v.end();
	for (_Type_iterator it=v.begin(); it!=it_end; ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void ShowElem(int elem) {
	if (elem%2 == 1) {
		return;
	}
	cout << elem << " ";
}

// int AddOne(int &elem, int add_base=0) {
// 	elem += add_base;
// 	cout << elem << " ";
// 	return elem;
// }
struct AddBase {
	typedef int first_argument_type;
	typedef int second_argument_type;
	typedef int result_type;
	AddBase(int _add_base=0) : add_base(_add_base) { };

	int const operator()(const int &elem, int _add_base) {
		return elem + _add_base;
	}
	int add_base;
};

#if 0
#endif
void Playgrand1() {
	vector<int> v1;
	for (int i=0; i<10; i++) {
		v1.push_back(i+1);
	}
	PrintVector(v1);
	for_each(v1.begin(), v1.end(), ShowElem);
	cout << endl;
	vector<int> v2;
	v2.resize(v1.size());
	// 自定义二元函数对象的绑定搞不明白，等会再研究吧
	transform(v1.begin(), v1.end(), v2.begin(), bind2nd<AddBase, int>(AddBase(), 10));
	PrintVector(v2);
	cout << endl;
}

template <typename T>
bool MyCompare1(T &lhs, T &rhs) {
	return lhs > rhs;
}

template <typename T>
struct MyCompare2
{
	bool operator()(T &lhs, T &rhs) {
		return lhs>rhs;
	}
};

bool MyCompare3(int &lhs, int &rhs) { // 从小到大
	return lhs < rhs;
}

void Playgrand2() {
	vector<int> v1;
	for (int i=0; i<10; i++) {
		v1.push_back(i+1);
	}
	PrintVector(v1);
	srand(time(NULL)); // 生成随机数种子
	random_shuffle(v1.begin(), v1.end());
	PrintVector(v1);

	// sort(v1.begin(), v1.end(), MyCompare2<int>()); // 函数对象，没有问题
	// sort(v1.begin(), v1.end(), MyCompare1); // 模板回调函数，这样写就问题。必须要指出模板的参数类型，就像下面一行。
	sort(v1.begin(), v1.end(), MyCompare1<int>);
	PrintVector(v1);
	sort(v1.begin(), v1.end(), MyCompare3); // 普通回调函数就可以直接用了
	PrintVector(v1);
}

void Playgrand3() {

}

void Playgrand4() {

}


int main() {
	// Playgrand1();
	Playgrand2();
	// Playgrand3();
	// Playgrand4();
	cout << "Run here!" << endl;
	return 0;
}

