#pragma once

#include <iostream>
using namespace std;

class Employee {
public:
    Employee();
    virtual ~Employee();

    // 获取员工薪资的方法
    virtual void GetSalaryMethod() = 0;
    // 员工升职方法
    virtual void UpLevelMethod(int add_level) = 0;
    // 初始化函数
    virtual void Init() = 0; 

    // 显示员工信息的接口
    void PrintEmployeeInfo();

protected:
    string name; // 员工姓名
    int id; // 员工id
    double salary; // 员工薪水
    int level; // 员工职级

    static int start_num;
};