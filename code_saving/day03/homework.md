1.  构造函数的种类，
    并举例说明。


2.  
```cpp
class Test 
   { 
    public:
      Test(int a, int b)
      {
          m_a = a;
          m_b = b;
      }        
      Test(Test &t)
     {
        cout<<“拷贝构造函数被执行”<<endl;
      }
      ~Test()
      {
           cout<<“析构函数被执行” <<endl;
       }
      int m_a;
      int m_b; 
    }
    void main(void)
    {
       Test t1, t2;
     }
```
说明t1和t2析构函数的执行顺序。
答：t2先进行析构，然后才是t1。不过这么声明有问题，没有与之匹配的构造函数。


3.   
 void test1() {
	Test t1(1, 2); 
	Test t2(t1); 
      }
分析test1（）函数中t1 和 t2 构造函数和析构函数调用情景。
答：先对t1进行带两个参数的构造，再对t2进行拷贝构造。析构时先析构t2，在析构t1。

4.  void test2() {
	Test t1(1, 2);
	Test t2 = t1;
    }
分析test2（）函数中t1 和 t2 构造函数和析构函数调用情景。
答：和题目3的情景相同。

5.  void func(Test t) {
	cout << "func begin..." << endl;
	cout << "func end..." << endl;
   }
   void test3() {
	cout << "test3 begin..." << endl;
	Test t1(10, 20); 
	//调用func函数
	func(t1);
	cout << "test3 end..." << endl;
   }
分析test3（）函数和 func（）函数中的 构造函数和析构函数调用情景。
答：传入class类型情况的拷贝构造。先进行t1的有参构造，在调用func()时对形参t进行拷贝构造。func()执行完成时析构t，test3()执行完成时析构t1。

6.
	Test gg() {  
		cout << "gg() begin..." << endl;
		Test temp(100, 200); //局部变量
		cout << "gg() before return temp" << endl;
		return temp;
	}
	void test4()
	{
		cout << "test4 begin..." << endl;
		gg(); 
		cout << "test4 end..." << endl;
	}
分析test4（）函数和 gg（）函数中的 构造函数和析构函数调用情景。
答：返回class类型情况的拷贝构造。gg()执行完成后发现test4()这边没有用来接它的东西，就直接析构了。这里涉及匿名对象的知识点，匿名对象需要好好的理解。

7. 	Test gg() {  
		cout << "gg() begin..." << endl;
		Test temp(100, 200); //局部变量
		cout << "gg() before return temp" << endl;
		return temp;
	}
	void test5() {
		cout << "test5 begin ..." << endl;
		Test t1 = gg();	
		cout << "test5 end..." << endl;
 	}
分析test5（）函数和 gg（）函数中的 构造函数和析构函数调用情景。
答：和题6相比，这次gg()返回的匿名对象有东西来接它。就不会被析构，直接转正了。

8. 	Test gg() {  
		cout << "gg() begin..." << endl;
		Test temp(100, 200); //局部变量
		cout << "gg() before return temp" << endl;
		return temp;
	}
       void test6()
       {
		cout << "test6 begin..." << endl;
		Test t1;
		t1 = gg(); 
		cout << "test6 end..." << endl;
	}
析test6（）函数和 gg（）函数中的 构造函数和析构函数调用情景。
答：和题7相比，这时的t1不是初始化，只是纯粹的赋值操作。所以gg()返回的匿名对象将成员变量赋值给t1后就被析构了。

9. 简述类的默认拷贝构造函数深拷贝和浅拷贝的问题。
答：默认的拷贝构造函数是浅拷贝，不会将对象所指向的内存也进行拷贝，只是机械地进行成员变量的拷贝。而深拷贝就是将对象所拥有的其他内存也进行拷贝，可以通过指针成员变量指向一块内存时的拷贝进行理解。

10. new 、 delete 和 malloc 和free的区别
new，delete是C++中的运算符，而malloc、free是C语言中的函数。
new会调用构造函数，delete会调用析构函数。而malloc、free只是直接地分配内存与释放内存。
```cpp
// 申请与释放基本类型内存空间
int *p1 = (int *)malloc(sizeof(int));
free(p1);
int *p2 = new int; 
// int *p2 = new int(100); // 基本类型可以在申请内存的同时进行初始化。
delete p2;

// 申请与释放复合类型内存空间，如数组a[10]
int *p3 = (int *)malloc(10 * sizeof(int));
free(p3);
int *p4 = new int[10]; 
delete [] p4;

// 申请与释放类类型内存空间。这里假设有类Test:
Test *p5 = (Test *)malloc(sizeof(Test));
free(p5);
Test *p6 = new Test; // 申请内存的同时执行了无参构造函数
// Test *p6 = new Test(1, 2); 还可以使用类中可用的构造函数
delete p6;

```

11. static修饰的类成员变量和成员函数的特点。
    如何初始化一个static修饰的成员变量。
    如何使用一个static修饰的成员函数？
答：static修饰的类成员变量局部于类，是所以该类实例化的对象共有的，不占类的内存空间。如果我们没有使用这个类，编译器就不会
给该静态成员变量分配内存。而当我们使用到这个类时，必须要再定义一这个成员变量，此时才会分配内存。具体的定义方法见该目录下的homework11.cpp。
static修饰的成员函数一定不能使用类中非静态成员变量。因为没有this指针，编译器也搞不懂到底哪个是哪个。