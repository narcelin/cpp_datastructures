/*
Feburary 2024

Loan Calculator
Assignment 2-3 for Programming 2 class taught by Dr. Sareh Raebi.
Creator: Nicolas Arcelin Ovando

*/

#include <iostream>
#include <cmath>
#include <array>

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
void InterestAndPrincipalCalculator(double* balance, float r, double m);
void TotalPaymentsAndInterestAccumulator(int n, double* balance, float r, double* m);
void DisplayTabularInformation();



int main(){
    double balance = 20000; // Loan Amount
    double apr = 10; //Annual Percentage Rate
    int n = 24; //Loan term in months

    double interest_amount = 0.00;
    double principal_amout = 0.00;

    // ValueInputer(&balance, &apr, &n);
    float r = AprConverter(apr);
    double m = AmortizationCalculator(balance, r, n); //Monthly payments

    InterestAndPrincipalCalculator(&balance, r, m);
    

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

void InterestAndPrincipalCalculator(double* balance_ptr, float r, double m){
    double interest_amount = (r * *balance_ptr);
    cout << interest_amount << endl;
    double principal_amount = m - interest_amount;
    cout << principal_amount;
    
    /*
    update interest value and principal value
    */
};

void TotalPaymentsAndInterestAccumulator(int n, double* balance, float r, double* m){
    double beginning_balance[n - 1];
    double ending_balance[n - 1];
    double interest_amounts[n - 1];
    double principal_amounts[n-1];

    while(n > 0){

    }
};

void DisplayTabularInformation();