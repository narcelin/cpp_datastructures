/*
COP3014: Programmming II
Lecture 02: Data Types and Arithmetic (Reference: "Problem Solving with C++", Walter Savitch)
Instructor: Sareh Taebi
*/

#include <iostream>
#include <string>     //needed for type string

using namespace std;

int main()
{
    //program I : char practice
    char symbol1, symbol2, symbol3;
    //prompt
    cout << "Enter two initials, without any periods:\n";
    cin >> symbol1 >> symbol2;

    //echo back the input
    cout << "The two initials are:\n";
    cout << symbol1 << symbol2 << endl;


    cout << "Once more with a space:\n";
    symbol3 = ' ';
    cout << symbol1 << symbol3 << symbol2 << endl;
    cout << "That's all.\n";

    //program II : string practice
//    string middle_name, pet_name;
//    string alter_ego_name;
//    cout << "Enter your middle name and the name of your pet separated by a space/enter.\n";
//    cin >> middle_name;
//    cin >> pet_name;
//
//     good example of classes and their value. Because string is a class, it supports the + sign
//    alter_ego_name = pet_name + " " + middle_name;
//
//    cout << "The name of your alter ego is ";
//    cout << alter_ego_name << "." << endl;
//
//    //program III : other data types
//    auto x = 2.4 *10;
//    uint16_t y = 366;
//    bool hi = 2;
//    cout <<"\ndata types " << x << "\t" << sizeof(y) << "\t" << hi << endl;

//    //program IV: Arithmetic
//    double divisor, dividend, quotient;
//    divisor = 3.0;
//    dividend = 5.0;
//    quotient = dividend / divisor;
//    cout << "\narithmetic result: " << quotient << endl;

    return 0;
}
