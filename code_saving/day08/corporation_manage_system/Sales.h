#pragma once 

#include "Employee.h"

class Sales : virtual public Employee {
public:
    Sales();
    virtual ~Sales();
    virtual void GetSalaryMethod();
    virtual void UpLevelMethod(int add_level);
    virtual void Init(); 
protected:
    double sale_amount; // 销售额
    double sale_persent; // 销售提成
};