#include <iostream>
/*
2. 定义两个命名空间A 和 B 分别在A中和B中定义变量value
  
   在main函数中将两个空间的value打印出来。
*/
namespace A {
	int value = 10;
}

namespace B {
	int value = 20;
}

int main(void) {
	std::cout << "namespace A  value: " << A::value << std::endl;
	std::cout << "namespace B  value: " << B::value << std::endl;
	return 0;
}