#include "SalesManager.h"

SalesManager::SalesManager() {

}

SalesManager::~SalesManager() {

}
// 获取员工薪资的方法
void SalesManager::GetSalaryMethod() {
    cout << "Please enter the sales amount: ";
    cin >> sale_amount;
    cout << "Please enter the sales persent you will get: ";
    cin >> sale_persent;
    salary = sale_amount*sale_persent + fix_salary;
}

// 员工升职方法
void SalesManager::UpLevelMethod(int add_level) {
    level += add_level;
}

// 初始化函数
void SalesManager::Init() {
    cout << "Please enter the SalesManager name: ";
    cin >> name;
    cout << "Please enter the fixed salary: ";
    cin >> fix_salary;    
}