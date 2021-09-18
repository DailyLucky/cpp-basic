// 定义抽象层
#pragma once
#include <iostream>

using namespace std;
// --------    抽象层 - --------------

//抽象的cpu类
class CPU
{
public:
	//抽象的计算方法
	virtual void caculate() = 0;
};

//抽象的显卡
class Card
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

// 这个应该可以看成是个包含多个接口的类
class Computer
{
public:
	Computer(CPU *cpu, Card *card, Memory *mem) ;

	//给电脑提供一个工作的方法
	void work();

	~Computer();

private:
	CPU *cpu;
	Card* card;
	Memory*mem;
};

// ----------------- 抽象层(end) -------------
