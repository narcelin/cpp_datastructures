/*
COP3014: Program to demonstrate call-by-reference parameters
Date: 02/07/2023
Taken from : "Problem Solving with C++", by Walter Savitch
*/


#include <iostream>
using namespace std;

/******* Function Prototypes ************/
void get_numbers(int& input1, int& input2);
//Reads two integers from the keyboard.
void swap_values(int& variable1, int& variable2);
//Interchanges the values of variable1 and variable2.
void show_results(int output1, int output2);
//Displays the outputs in order of output1, output2.
void order(int& n1, int& n2);
//Orders the numbers in the variables n1 and n2
//so that after the function call n1 <= n2.


int main( )
{
int first_num = 0, second_num = 0;

get_numbers(first_num, second_num);
///////////////////////////////////Use this set of function calls to change the order of values ALL THE TIME

swap_values(first_num, second_num);
cout << "In reverse order the numbers are: ";
show_results(first_num, second_num);

//////////////////////////////////Use this set of function calls to change the order of values Only to achieve first_num < second_num
order(first_num, second_num);
cout << "In increasing order the numbers are: ";
show_results(first_num, second_num);



return 0;
}

//function that reads inputs
void get_numbers (int& input1, int& input2)
{
cout << "Enter two integers: ";
cin >> input1
>> input2;
}

//function that swaps two values in memory
void swap_values(int& variable1, int& variable2)
{
int temp;
temp = variable1;
variable1 = variable2;
variable2 = temp;
}


//functions calling functions! Ensure that always n1 <= n2
void order(int& n1, int& n2)
{
if (n1 > n2)
    swap_values(n1, n2);
}

//function to show results in increasing order
void show_results(int output1, int output2)
{

cout << output1 << " " << output2 << endl;
}
