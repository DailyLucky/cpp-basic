#pragma once 

#include "Employee.h"

class Technician : public Employee {
public:
    Technician();
    virtual ~Technician();

    virtual void GetSalaryMethod();
    virtual void UpLevelMethod(int add_level);
    virtual void Init(); 
protected:
    double PerHourMoney;
    int workhour;
};

