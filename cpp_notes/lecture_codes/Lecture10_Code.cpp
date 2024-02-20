/*
COP3014: STRUCTURES as an intro to classes
Instructor: Sareh Taebi, PhD

*/

#include <iostream>

using namespace std;

//***************************** Structure for a bank certificate of deposit: It's a public data structure and any function can use it *********************************
struct CDAccount
{
double balance;
double interest_rate;
int term; //months until maturity
};


// Other Structs to show the hierarchy in Strucs
struct Date
{
   int month;
   int day;
   int year;
};

struct PersonInfo
{
double height; //in inches
int weight; //in pounds
Date birthday;
};



//************************ Function prototypes for structures: Using call by reference and call by value, also returning structs **************************
void get_data(CDAccount& the_account);
//Postcondition: the_account.balance and the_account.interest_rate have been given values that the user entered at the keyboard.

CDAccount make_account(double the_balance, double the_rate, int the_term);
//precondition: Takes three values of type double and int
//postcondition: Returns a value of type CDAccount

void get_BD(Date& Birthday);
//Postcondition: the date, month and year have been entered by the user through the keyboard.


int main()
{

////////////////////////////////// First Struct //////////////////////////////////////////////////////////////////////////
CDAccount account;


get_data(account);       //function call

double rate_fraction, interest;
rate_fraction = account.interest_rate / 100.0;
interest = account.balance * rate_fraction * (account.term / 12.0);
account.balance = account.balance + interest;

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
cout << "When your CD matures in "
<< account.term << " months,\n"
<< "it will have a balance of $"
<< account.balance << endl;


CDAccount new_account;
new_account = make_account(10000.00, 5.1, 11);    //function call return a data variable of type CDAccount

CDAccount example_account = {2000, 4, 11};  //directly initialize the CDA
cout << "\nexample_account: " << example_account.term << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////// Second Struct //////////////////////////////////////////////////////////////////////////

PersonInfo Alice;    //declare Alice of type PersonInfo
get_BD(Alice.birthday);           //function call
//get_height_weight(Alice);  //this function does not exist, create it on your own!

Alice = {50, 100, Alice.birthday};
cout << "Alice's height: " << Alice.height << endl;
cout << "Alice's weight: " << Alice.weight << endl;
cout << "Alice's birthday : "<< Alice.birthday.day << '/' << Alice.birthday.month << '/' << Alice.birthday.year ;


//Note all the initializations. what happens here?
Date due_date1 = {12, 21};    //year becomes zero here
//Date due_date2 = {12, 21, 20, 22};   //this is a syntax error
Date due_date3 = {12, 21, 22};   //this is correct 12/21/22 is the due date3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

return 0;

}


//Uses iostream
void get_data(CDAccount& the_account)
{
cout << "Enter account balance: $";
cin >> the_account.balance;
cout << "Enter account interest rate (in percentage): ";
cin >> the_account.interest_rate;
cout << "Enter the number of months until maturity\n"
<< "(must be 12 or fewer months): ";
cin >> the_account.term;
}


//returns a value of type CDAccount
CDAccount make_account(double the_balance, double the_rate, int the_term)
{
CDAccount temp;
temp.balance = the_balance;
temp.interest_rate = the_rate;
temp.term = the_term;
return temp;
}

void get_BD(Date& Birthday)
{
cout << "Enter birth day: ";
cin >> Birthday.day;
cout << "Enter birth month: ";
cin >> Birthday.month;
cout << "Enter birth year: ";
cin >> Birthday.year;
}
