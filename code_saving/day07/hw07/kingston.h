#pragma once
#include <iostream>
#include "computer_assemble.h"
using namespace std;

class KingstonMem :public Memory
{
public:
	virtual void storage();
};