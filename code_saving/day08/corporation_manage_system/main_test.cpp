// 企业员工管理
#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "SalesManager.h"
#include "Technician.h"
#include "Sales.h"

using namespace std;

int main() {
	Employee *emp_array[] = {new Manager, new Technician, new Sales, new SalesManager};

	for (int i=0; i<sizeof(emp_array)/sizeof(emp_array[0]); i++) {
		emp_array[i]->Init();
		emp_array[i]->GetSalaryMethod();
		emp_array[i]->UpLevelMethod(1);
		emp_array[i]->PrintEmployeeInfo();
	}
	for (int i=0; i<sizeof(emp_array)/sizeof(emp_array[0]); i++) {
		if (emp_array[i] != NULL) {
			delete emp_array[i];
			emp_array[i] = NULL;
		}
	}
	cout << "Run here!" << endl;
	return 0;
}