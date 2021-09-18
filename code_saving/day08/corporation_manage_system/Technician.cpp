#include "Technician.h"

Technician::Technician() : PerHourMoney(0), workhour(0) {
    cout << "Technician()..." << endl;
}

Technician::~Technician() {
    cout << "~Technician()..." << endl;
}

void Technician::GetSalaryMethod() {
    cout << "Please enter the work hour: ";
    cin >> workhour;
    salary = PerHourMoney * workhour;
}

void Technician::UpLevelMethod(int add_level) {
    level += add_level;
}

void Technician::Init() {
    cout << "Please enter the Technician name: ";
    cin >> name;
    cout << "Please enter the hour money: ";
    cin >> PerHourMoney;
} 