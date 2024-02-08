/*
Feburary 2024

Loan Calculator
Assignment 2-3 for Programming 2 class taught by Dr. Sareh Raebi.
Creator: Nicolas Arcelin Ovando

*/

#include <iostream>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

/* PSUDO CODE

Inputs: loan amount (P), annual percentage rate (APR), loan term(n) - in years and/or months

Goal: claculates and displays the monthly payments and balance of loan until the load is paid off. Known as "amortization schedule"

Monthly payments calculated using amortization equations: | M = P ((r(1+r)^n)/((1+r)^n)-1) | M = monthly payments, P is principal load, r is the monthly interest rate and n is the number of pauments over loan's lifetime.

r = (1+ (APR/100)^1/12) - 1

*/

//Pointers for the functions?? call by reference

void ValueInputer(double* balance, double* apr, int* n);
float AprConverter(double apr);
double AmortizationCalculator(int balance, float r, int n);
void InterestAndPrincipalCalculator(double* balance, float r, double* payment_amount, double* interest_amount, double* principal_amount);
void TotalPaymentsAndInterestAccumulator(int n, double* balance_ptr, float r, double* payment_amount, double* interest_amount, double* principal_amount, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]);
void DisplayTabularInformation(int n, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]);



int main(){
    double balance = 20000; // Loan Amount
    double apr = 10; //Annual Percentage Rate
    int n = 24; //Loan term in months

    double interest_amount = 0.00;
    double principal_amount = 0.00;

    // ValueInputer(&balance, &apr, &n);
    float r = AprConverter(apr);
    double payment_amount = AmortizationCalculator(balance, r, n); //Monthly payments


    double beginning_balances[n - 1];
    double ending_balances[n - 1];
    double interest_amounts[n - 1];
    double principal_amounts[n-1];


    TotalPaymentsAndInterestAccumulator(n, &balance, r, &payment_amount, &interest_amount, &principal_amount, beginning_balances, ending_balances, interest_amounts, principal_amounts);
    DisplayTabularInformation(n, beginning_balances, ending_balances, interest_amounts, principal_amounts);

    return 0;
}



void ValueInputer(double* balance_ptr, double* apr_ptr, int* n_ptr){ 

    cout << "----- Input the following values -----" << endl;
   
    cout << "Loan Amount (P): ";
    cin >> *balance_ptr;
    
    cout << "Annual Percentage Rate (APR): ";
    cin >> *apr_ptr;
   
    cout << "Loan Term \"in months\" (n): ";
    cin >> *n_ptr;

};

float AprConverter(double apr){
    float r = (pow((1+(apr/100)),(1.0/12))) - 1; //Monthly interest rate
    return r;
};

double AmortizationCalculator(int balance, float r, int n){
    return(balance * (r * pow((1 + r), n))/(pow((1 + r), n) - 1));
};

void InterestAndPrincipalCalculator(double* balance_ptr, float r, double* payment_amount, double* interest_amount, double* principal_amount){
    *interest_amount = (r * *balance_ptr);
    *principal_amount = *payment_amount - *interest_amount;
    *balance_ptr = *balance_ptr - *principal_amount;
    // cout << "NEW LINE" << endl << *payment_amount << endl << *interest_amount << endl << *principal_amount << endl << *balance_ptr << endl;
    
    /*
    update interest value and principal value
    */
};

void TotalPaymentsAndInterestAccumulator(int n, double* balance_ptr, float r, double* payment_amount, double* interest_amount, double* principal_amount, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]){ 


    for(int i = 0; i < n; i++){
        beginning_balances[i] = *balance_ptr;
        InterestAndPrincipalCalculator(balance_ptr, r, payment_amount, interest_amount, principal_amount);
        interest_amounts[i] = *interest_amount;
        principal_amounts[i] = *principal_amount;
        ending_balances[i] = *balance_ptr;
    }
};

void DisplayTabularInformation(int n, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]){
    cout.width(4);
    cout << "Index \t" << "Beginning Balance \t" << "Interest \t" << "Principal \t" << "Ending Balance" << endl;

    for(int i = 0; i < n; i++){
        cout << i << "\t" << beginning_balances[i] << "\t\t\t" << interest_amounts[i] << "\t\t" << principal_amounts[i] << "\t\t" << ending_balances[i] << endl;

    }
};

/*
ISSUES:

Balance is rounding to the nearest decimal for some reason 
*/