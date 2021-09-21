#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// set
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
	friend class TeacherCompare;
private:
	string name;
	int age;
};

// Functor 函数对象 仿函数   称号有点多哈
template <typename _Key, typename _value>
struct MyCompare {
	// 提供给set的大小比较的仿函数，排序为按年龄从小到大
	// !!! 这里的两个参数也必须设置为const类型，不然编译会报错，匹配非常严格。
	// bool operator()(const Teacher &left, const Teacher &right) {
	// 	return left.age < right.age;
	// }
	// 按姓名进行排序
	bool operator()(const _Key &left, const _Key &right) {
		return (left > right);
	}
};
// 适用于基本类型
// template <typename T>
template<typename _Key, typename _Value, typename _Compare = std::less<_Key>>
void PrintMap(map<_Key, _Value, _Compare> &m) {
	typedef typename map<_Key, _Value, _Compare>::iterator iterator;
	iterator end_it = m.end();
	// map中的每一个元素是pair，迭代器可以粗略的理解为指向pair的指针
	for (iterator it=m.begin(); it!=end_it; ++it) {
		cout << it->first << "  " << it->second << endl;
	}
	cout << endl;
}
typedef map<char, int, MyCompare<char, int>>::iterator iterator2;

#if 0

void Playgrand1() {
	// map类对象的初始化与插入
	map<char, int, MyCompare<char, int>> m1;
	m1.insert(pair<char,int>('A', 90));
	m1.insert(pair<char,int>('C', 70));
	m1.insert(pair<char,int>('d', 60));
	m1.insert(pair<char,int>('B', 80));
	m1.insert({pair<char,int>('e', 60), pair<char,int>('f', 50)});
	m1.insert(make_pair('M', 50));
	PrintMap<char, int>(m1);
}
#endif
void Playgrand2() {
	map<char, int, MyCompare<char, int>> m1;
	m1.insert(pair<char,int>('A', 90));
	m1.insert(pair<char,int>('C', 70));
	m1.insert(pair<char,int>('d', 60));
	m1.insert(pair<char,int>('B', 80));
	m1.insert({pair<char,int>('e', 60), pair<char,int>('f', 50)});
	m1.insert(make_pair('M', 50));
	PrintMap<char, int>(m1);
	m1.erase('A');
	iterator2 del_pos_it = m1.find('d');
	m1.erase(del_pos_it);
	PrintMap(m1);

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

