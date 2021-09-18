#pragma once
#include <iostream>
#include "computer_assemble.h"
using namespace std;

class IntelCPU :public CPU
{
public:
	virtual void caculate();
};

class IntelCard :public Card
{
public:
	virtual void display();
};

class IntelMem :public Memory
{
public:
	virtual void storage();
};