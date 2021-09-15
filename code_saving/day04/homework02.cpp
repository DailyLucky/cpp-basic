#include <iostream>

using namespace std;

class Test {
public:
	Test(int a=0, int b=0) : m_a(a), m_b(b) {} // 该构造函数可以兼容无参、1个参数、2个参数的对象构造
    ~Test() {}
    // 友元函数的位置不会受到访问控制标签的影响。放在类中任意位置都行。
    
    friend void FriendFunc02(Test &obj, int val);
private:
	int m_a;
	int m_b;
    friend void FriendFunc01(Test *pobj, int val);
};

// 操作私有成员变量的友元函数
void FriendFunc01(Test *pobj, int val) {
    pobj->m_a = val;
    pobj->m_b = val;
}

void FriendFunc02(Test &obj, int val) {
    obj.m_a = val;
    obj.m_b = val;
}

int main() {
    Test t1;
    Test t2(20);
    Test t3(30, 40);
    FriendFunc01(&t1, 100);
    FriendFunc02(t2, 200);
    cout << "Run here!" << endl;
	return 0;
}