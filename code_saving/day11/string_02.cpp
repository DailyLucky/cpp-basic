#include <iostream>
#include <string>

#include <algorithm>
#include <cctype>

using namespace std;

// 测试案例。这么写还挺好，做完测试可以直接把 #endif 往下面移动下就可以屏蔽最新的测试代码，nice。
#if 0
void Playgrand1() {
	// 初始化字符串的方法
	string s1 = "I'm string 1";
	string s2("I'm string 2"); // 有参构造

	string s3 = s1; // 拷贝构造
	string s4(s2); // 拷贝构造

	string s5; // 无参构造

	string s6(5, 'a'); // 有参构造，有参数构造存在函数重载

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << "s5:<" << s5 << ">!" << endl; // 无参构造的结果是一个空串
	cout << "s6:<" << s6 << ">!" << endl;
}

void Playgrand2() {
	// 根据索引查找、修改元素
	string s1(5, 'a');
	s1[0] = 'b';
	s1.at(2) = 'c';
	cout << "s1:<" << s1 << ">" << endl;
}

void Playgrand3() {
	// 将string类的指针露出来
	string s1 = "aaabbbcccddd";
	char *ps = const_cast<char *>(s1.c_str()); // 这里还刚好可以复习一手取消只读属性转换const_cast<>
	cout << "s1:<" << s1 << ">" << endl;
	printf("ps:<%s>\n", ps);
}

void Playgrand4() {
	string s1("abcdefghijk");
	char *ps1 = new char[s1.length() + 1]; // 分配足够大的空间
	char *ps2 = new char[s1.length() + 1]; // 分配足够大的空间
	//   template<typename _CharT, typename _Traits, typename _Alloc>
    // typename basic_string<_CharT, _Traits, _Alloc>::size_type
    // basic_string<_CharT, _Traits, _Alloc>::
    // copy(_CharT* __s, size_type __n, size_type __pos) const
	s1.copy(ps1, 5, 0);
	s1.copy(ps2, 3, 6);
	cout << "s1:<" << s1 << ">" << endl;
	cout << "ps1:<" << ps1 << ">" << endl;
	cout << "ps2:<" << ps2 << ">" << endl;
}

void Playgrand5() {
	// 字符串的赋值测试
	string s1;
	string s2("Tang");
	string s3("bbbdddejiao");
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
	cout << "s3:<" << s3 << ">" << endl;
	// 用 = 进行拷贝赋值
	s1 = s2;
	cout << "s1:<" << s1 << ">" << endl;
	// 使用成员函数assign()赋值，该函数有多种重载
	s2.assign("Rui!");
	cout << "s2:<" << s2 << ">" << endl;
	s2.assign("Rui!", 2);
	cout << "s2:<" << s2 << ">" << endl;
	s2.assign(s3);
	cout << "s2:<" << s2 << ">" << endl;
	s2.assign(10, 'a');
	cout << "s2:<" << s2 << ">" << endl;
	s2.assign(s2, 4, 4);
	cout << "s2:<" << s2 << ">" << endl;
}

void Playgrand6() {
	// 字符串连接测试
	string s1("Hello");
	string s2("Tang");
	string s3("bbbdddejiao");
	string s4; // 空串
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
	cout << "s3:<" << s3 << ">" << endl;
	s1 += ", world!";
	s2 += s1;
	s4.append(s2, 2, 4);
	s4.append(3, '1').append(3, '!');
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
	cout << "s3:<" << s3 << ">" << endl;
	cout << "s4:<" << s4 << ">" << endl;
}

void Playgrand7() {
	string s1("highsk");
	string s2("sbhsin");
	string s3("highskmns");
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
	cout << "s3:<" << s3 << ">" << endl;
	if (s1.compare(s2) > 0) {
		cout << "s1 > s2" << endl;
	}
	if (s1.compare(s3) >= 0) {
		cout << "s1 >= s3" << endl;
	} else {
		cout << "s1 < s3" << endl;
	}
	// 重载了 < 操作符，不过从源码上看也是你用了成员函数compare()
	// operator<() 的返回值是bool类型
	// compare() 的返回值是int类型
	if (s1 < s2) {
		cout << "s1 < s2" << endl;
	}
}

void Playgrand8() {
	// 获取源字符串的子串
	string s1 = "aab dhi abc aac jihdaab llcniabbaab!!";
	string s2 = s1.substr(3, 15);
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
}

void Playgrand9() {
	// 查找函数测试， 反向查找rfind()我没有做，用起来都差不多
	string s1 = "aab dhi abc aac jihdaab llcniaabbaab!!";
	int appear_tiems = 0;
	int pos = 0;
	// 查找不到时会返回 npos，也就是-1 ，这是判断结束的标志
	while ((pos=s1.find("aab", pos)) != -1) {
		++pos; // 指针后移一位
		++appear_tiems;
	}
	cout << "\"aab\" appear times is "  << appear_tiems << endl;
}

void Playgrand10() {
	// 替换函数测试
	string s1 = "aaabbbcccddd";
	cout << "s1:<" << s1 << ">" << endl;
	string s2 = s1.replace(0, 3, "");
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
	string s4("aaaazzz");
	s4.replace(3, 1, s2);
	cout << "s4:<" << s4 << ">" << endl;
	s2.swap(s4);
	cout << "s2:<" << s2 << ">" << endl;
	cout << "s4:<" << s4 << ">" << endl;
}

void Playgrand11() {
	// 插入与删除函数测试
	string s1(1, 'a');
	cout << "s1:<" << s1 << ">" << endl;
	for (int i=0; i<5; i++) {
		s1.insert(s1.end(), 'b');
	}
	cout << "s1:<" << s1 << ">" << endl;
	for (string::iterator it=s1.begin(); it!=s1.end(); it++) { // 通过迭代器进行遍历
		cout << *it << " ";
	}
	cout << endl;
	// insert part
	s1.insert(1, "???");
	cout << "s1:<" << s1 << ">" << endl;
	s1.insert(5, string("!!!"));
	cout << "s1:<" << s1 << ">" << endl;
	// erase part
	s1.erase(3, 3);
	cout << "s1:<" << s1 << ">" << endl;
	s1.erase(); // 不给参数时默认是删除所有，因为函数给的默认参数是删除所有
	cout << "s1:<" << s1 << ">" << endl;
}
#endif

void Playgrand12() {
	// 来一点算法相关的
	string s1 = "AaBbCc";
	string s2(s1.length(), ' ');
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
	// 这里有点问题，搞不定...
	// 找到问题了解决方法了 :)
	// http://www.dovov.com/std-transformtoupper.html
	// 我去，这里太细了
	// 前面由于写了 using namespace std;
	// transform(s1.begin(), s1.end(), s2.begin(), toupper);  这里不加上域作用符的话会调用std::toupper()
	// 然而我们要用的是不是它，所以造成不匹配的问题，这里需要显式的加上 :: ，全局命名空间域作用符 
	// transform(s1.begin(), s1.end(), s2.begin(), ::toupper); 
	// 下面这种是比较专业的做法，转化为这种函数指针类型，指明了函数的参数类型和返回值类型。很牛。
	// transform(s1.begin(), s1.end(), s2.begin(), (int (*)(int ))toupper); 
	transform(s1.begin(), s1.end(), s2.begin(), (int (*)(int ))toupper); 
	cout << "s1:<" << s1 << ">" << endl;
	cout << "s2:<" << s2 << ">" << endl;
}

int main() {
	// Playgrand1();
	// Playgrand2();
	// Playgrand3();
	// Playgrand4();
	// Playgrand5();
	// Playgrand6();
	// Playgrand7();
	// Playgrand8();
	// Playgrand9();
	// Playgrand10();
	// Playgrand11();
	// Playgrand12();
	cout << "Run here!" << endl;
	return 0;
}