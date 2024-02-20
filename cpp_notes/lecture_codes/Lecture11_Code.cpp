/*Lecture 11: Learning to define classes, concept of encapsulation
Code taken from: "Problem-Solving with C++", by W. Savitch
Instructor: Sareh Taebi, PhD
Date: 10/06/2022
*/

#include <iostream>

using namespace std;

//Purpose of this class: store a date (whether it's a birthday or an event)
class DayOfYear
{
    public:
        void input( );
        void output( );
        void set_date(int new_month, int new_day);
        //Precondition: new_month and new_day form a possible date.
        //Postcondition: The date is reset according to the arguments.
        int get_month( );
        //Returns the month, 1 for January, 2 for February, etc.
        int get_day( );
        //Returns the day of the month.
    private:
        void check_date( );
        int month;
        int day;
};

//testing out classes
int main()
{
DayOfYear today, bach_birthday;
cout << "Enter today's date.\n";
today.input( );
cout << "Today's date is ";
today.output( );
bach_birthday.set_date(3, 21);
cout << "J. S. Bach's birthday is ";
bach_birthday.output( );
if (today.get_month( ) == bach_birthday.get_month( ) && today.get_day( ) == bach_birthday.get_day( ) )
 cout << "Happy Birthday Johann Sebastian!\n";
else
cout << "Happy Unbirthday Johann Sebastian!\n";


today = bach_birthday;           //assignment operator would set values of bach_birthday to today's values
cout << "Now again! I have set today's date to that of Bach's birthday\n";
if (today.get_month( ) == bach_birthday.get_month( ) && today.get_day( ) == bach_birthday.get_day( ) )
 cout << "Happy Birthday Johann Sebastian!\n";
else
cout << "Happy Unbirthday Johann Sebastian!\n";

return 0;
}

void DayOfYear::input( )
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    check_date( );
}


void DayOfYear::output( )
{
    cout << "month = " << month << ", day = " << day << endl;
}


void DayOfYear::set_date(int new_month, int new_day)
{
    month = new_month;
    day = new_day;
    check_date();
}

void DayOfYear::check_date( )
{
if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
{   //input();
cout << "Illegal date. Aborting program.\n";
exit(1);
}
}

int DayOfYear::get_month( )
{
    return month;
}

int DayOfYear::get_day( )
{
    return day;
}
