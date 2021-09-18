#include "Employee.h"

// 初始化类共有静态变量
int Employee::start_num = 1000;

Employee::Employee() {
    level = 1;
    salary = 0.0;
    id = start_num++;
    cout << "Employee()..." << endl;
}

Employee::~Employee() {
    cout << "~Employee()..." << endl;
}

void Employee::PrintEmployeeInfo() {
    cout << "name  : " << name << endl;
    cout << "id    : " << id << endl;
    cout << "level : " << level << endl;
    cout << "current month salary: " << salary << endl;
}
