/*
Using structs
*/

#include <iostream>

using namespace std;

    struct CDAccount {  //capatalization nomenclature
        double balance;
        double interest;
        int term;
    };

int main(){
    CDAccount my_account = {5000, 0.05, 12}, your_account = {1000, 0.04, 12};

    my_account.balance += 5000;
    your_account.balance += 2300;


    return 0;
};