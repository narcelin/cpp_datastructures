/*
Classes & Encapsulation
Feb 20 Class
*/

#include <iostream>

using namespace std;

class Class_Name {
    public:
        // Member_Specification_1
        // Member_Specification_2
    private:
        // Member_Specification_3
        // Member_Specification_4
};

class DayOfYear {
    public:
        void output(int month, int day);
        int month;
        int day;
};

int main(){
    return 0;
}

void DayOfYear::output(int month, int day) { 
    cout << "month - " << month << ", day = " << day << endl;
}