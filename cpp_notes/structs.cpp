/*
Using structs
*/

#include <iostream>
#include <string>

using namespace std;


    struct CDAccount {  //capatalization nomenclature
    //can also set default values in here.
        double balance;
        double interest;
        int term;
    };

    struct EmployeeRecord {
        double wage_rate;
        int accrued_vacation_days;
        char work_status;
    };

    EmployeeRecord new_employee_record(double wage_rate, int accrued_vacation_days, char work_status);
    void read_employee_record(EmployeeRecord employee_record);

int main(){

    // CDAccount my_account = {5000, 0.05, 12}, your_account = {1000, 0.04, 12};
    // my_account.balance += 5000;
    // your_account.balance += 2300;

    EmployeeRecord record = new_employee_record(34.50, 5, 'H');
    read_employee_record(record);


    return 0;
};

    EmployeeRecord new_employee_record(double wage_rate, int accrued_vacation_days, char work_status){
        EmployeeRecord tempER = {wage_rate, accrued_vacation_days, work_status};
        return (tempER);
    };

    void read_employee_record(EmployeeRecord employee_record){
        cout << "Wage Rate: " << employee_record.wage_rate << endl;
        cout << "Vacation Days: " << employee_record.accrued_vacation_days << endl;
        cout << "Work Status: " << employee_record.work_status << endl;
    };
