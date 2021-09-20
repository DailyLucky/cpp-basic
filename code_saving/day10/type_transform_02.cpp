/*
    dynamic_cast、reinterpret_cast测试
*/

#include <iostream>

using namespace std;

class A
{
public:
	virtual void func() {
		cout << "A" << endl;
	}
	int a;
};

class B :public A
{
public:
	virtual void func() {
		cout << "B" << endl;
	}
	int b;
};

//动物的抽象类
class Animal
{
public:
	virtual void cry() = 0;// 纯虚函数
	virtual void doHome() = 0;// 纯虚函数
};

class Dog :public Animal {
public:
	virtual void cry()  {
		cout << "WangWang!" << endl;
	}

	void doHome() {
		cout << "Watch home!" << endl;
	}
};

class Cat :public Animal {
public:
	virtual void cry() {
		cout << "MiaoMiao!" << endl;
	}
	void doHome() {
		cout << "Catch Mouse" << endl;
	}
};



int main01(void)
{
	Animal *animal = NULL;
	animal = new Dog;
	animal->cry();
	Dog *dog = new Dog;
	cout << " ----- " << endl;
	dog =  dynamic_cast<Dog*> (animal);
	if (dog != NULL) {
		cout << "转换成功" << endl;
		dog->cry();
		dog->doHome();
	}
	else {
		cout << "转换失败" << endl;
	}
	//dynamic _cast 是将父类转换成子类。让老子变成儿子。
	//让子类指针执行父类的对象。
	Cat *cat = dynamic_cast<Cat*>(animal);
	//准备试图让一只狗变成一只猫
	if (cat != NULL) {
		cout << "转换成功" << endl;
		cat->cry();
		cat->doHome();
	}
	else {
		cout << "转换失败" << endl;
	}
	A *ap = new A;
	B *bp = dynamic_cast<B*>(ap);
	if (bp != NULL) {
		bp->func();
	}
	return 0;
}

// 父类对象指针转为子类对象指针测试
void Playgrand1(Animal *obj) {
    obj->cry();
    A *pa = dynamic_cast<A *>(obj);
    if (pa == NULL) {
        cout << "Transform failed" << endl;
    }
    Dog *pd = dynamic_cast<Dog *>(obj);
    if (pd != NULL) {
        pd->doHome();
    }
    Cat *pc = dynamic_cast<Cat *>(obj);
    if (pc != NULL) {
        pc->doHome();
    }
}

void Playgrand2() {
    int *p_int = NULL;
    // char *p_char = "I am char ptr"; // 字符串常量转换为char *已经被ISO禁止了
    char p_char2[] = "I am char ptr";
    // p_int = p_char;
    // p_int = static_cast<int *>(p_char);
    // p_int = dynamic_cast<int *>(p_char);
    p_int = reinterpret_cast<int *>(p_char2);
    cout << p_char2 << endl;
    cout << p_int << endl;
}

void Playgrand3() {
    A *pa = NULL;
    // B *pb = pa;
    B *pb1 = static_cast<B *>(pa);
    B *pb2 = NULL;
    A *pa2 = pb2;
}

int main() {
    Dog d1;
    Cat c1;
    Playgrand1(&d1);
    Playgrand1(&c1);
    Playgrand2();

	cout << "Run here!" << endl;
	return 0;
}