#include "Sales.h"

Sales::Sales() : sale_amount(0), sale_persent(0.1) {

}

Sales::~Sales() {

}

void Sales::GetSalaryMethod() {
    cout << "Please enter the sales amount: ";
    cin >> sale_amount;
    cout << "Please enter the sales persent you will get: ";
    cin >> sale_persent;
    salary = sale_amount*sale_persent;
}

void Sales::UpLevelMethod(int add_level) {
    level += add_level;
}

void Sales::Init() {
    cout << "Please enter the Sales name: ";
    cin >> name;
}