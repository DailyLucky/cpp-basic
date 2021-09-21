#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// set
// 一、容器 set/multiset 的使用方法； 红黑树的变体，查找效率高，插入不能指定位置，插入时自动排序。
// 二、functor 的使用方法； 类似于函数的功能，可用来自定义一些规则，如元素比较规则。
// 三、pair 的使用方法。 对组，一个整体的单元，存放两个类型(T1,T2，T1 可与 T2 一样)的两个元素。
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
		out << t.name << "\t" << t.age;
		return out;
	}
	friend class TeacherCompare;
private:
	string name;
	int age;
};

// Functor 函数对象 仿函数   称号有点多哈
struct TeacherCompare {
	// 提供给set的大小比较的仿函数，排序为按年龄从小到大
	// !!! 这里的两个参数也必须设置为const类型，不然编译会报错，匹配非常严格。
	// bool operator()(const Teacher &left, const Teacher &right) {
	// 	return left.age < right.age;
	// }
	// 按姓名进行排序
	bool operator()(const Teacher &left, const Teacher &right) {
		return (left.name<right.name);
	}
};
// 适用于基本类型
// template <typename T>
template<typename _Key, typename _Compare = std::less<_Key>>
void PrintSet(set<_Key, _Compare> &s) {
	typedef typename set<_Key, _Compare>::iterator iterator;
	iterator end_it = s.end();
	for (iterator it=s.begin(); it!=end_it; ++it) {
		cout << *it << " ";
	}
	cout << endl;
}


#if 0

void Playgrand1() {
	set<int> s1; // 等价于set<int, less<int>> s1; 默认函数对象是less<type>
	s1.insert(3);
	s1.insert(6);
	s1.insert(-1);
	s1.insert(2);
	s1.insert(20);
	PrintSet(s1);
	set<int, greater<int>> s2;
	s2.insert(3);
	s2.insert(6);
	s2.insert(-1);
	s2.insert(2);
	s2.insert(20);
	PrintSet(s2);
	// set<int, greater<int>>::iterator end_it = s2.end();
	// for (set<int, greater<int>>::iterator it=s2.begin(); it!=end_it; ++it) {
	// 	cout << *it << " ";
	// }
	// cout << endl;
}

void Playgrand2() {
	set<Teacher, TeacherCompare> s1;
	s1.insert(Teacher("tang", 22));
	s1.insert(Teacher("zhao", 18));
	s1.insert(Teacher("wang", 30));
	s1.insert(Teacher("lu", 24));
	// PrintSet(s1);
	set<Teacher, TeacherCompare>::iterator end_it = s1.end();
	for (set<Teacher, TeacherCompare>::iterator it=s1.begin(); it!=end_it; ++it) {
		cout << (*it) << endl; // 重载的 << 运算符必须给第二个参数加上const
	}
	cout << endl;
}

void Playgrand3() {
	set<Teacher, TeacherCompare> s1;
	s1.insert(Teacher("tang", 22));
	s1.insert(Teacher("zhao", 18));
	s1.insert(Teacher("wang", 30));
	s1.insert(Teacher("lu", 24));
	// 自定义查找的结果有点玄学啊
	if (s1.find(Teacher("tang", 22)) != s1.end()) { 
		cout << "Find it!" << endl;
	}
}

void Playgrand4() {
	// pair<> 对组测试
	set<int> s1;
	for (int i=0; i<10; ++i) {
		s1.insert(i+1);
	}
	pair<set<int>::iterator, set<int>::iterator> pair_it = s1.equal_range(5);
	cout << *pair_it.first << endl;
	cout << *pair_it.second << endl;
	
}
#endif

int main() {
	// Playgrand1();
	// Playgrand2();
	// Playgrand3();
	// Playgrand4();
	cout << "Run here!" << endl;
	return 0;
}

