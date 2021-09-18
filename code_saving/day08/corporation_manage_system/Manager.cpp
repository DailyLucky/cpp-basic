#include "Manager.h"

Manager::Manager() : fix_salary(6000) {
    cout << "Manager()..." << endl;
}

Manager::~Manager() {
    cout << "~Manager()..." << endl;
}

void Manager::GetSalaryMethod() {
    salary += fix_salary;
}

void Manager::UpLevelMethod(int add_level) {
    level += add_level;
}

void Manager::Init() {
    cout << "Please enter the Manager name: ";
    cin >> name;
    cout << "Please enter the fixed salary: ";
    cin >> fix_salary;
}