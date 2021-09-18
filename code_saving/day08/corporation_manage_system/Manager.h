#pragma once 

#include "Employee.h"

class Manager : virtual public Employee {
public:
    Manager();
    virtual ~Manager();
    
    virtual void GetSalaryMethod();
    virtual void UpLevelMethod(int add_level);
    virtual void Init(); 
protected:
    double fix_salary;
};