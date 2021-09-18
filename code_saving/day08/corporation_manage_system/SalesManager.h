#pragma once

#include "Sales.h"
#include "Manager.h"

// 销售经理类
class SalesManager : public Manager, public Sales {
public:
    SalesManager();
    virtual ~SalesManager();
    // 获取员工薪资的方法
    virtual void GetSalaryMethod();
    // 员工升职方法
    virtual void UpLevelMethod(int add_level);
    // 初始化函数
    virtual void Init(); 

};