/*
Feburary 2024

Loan Calculator
Assignment 2-3 for Programming 2 class taught by Dr. Sareh Raebi.
Creator: Nicolas Arcelin Ovando

*/

#include <iostream>
#include <array>

using namespace std;

/* PSUDO CODE

Inputs: loan amount (P), annual percentage rate (APR), loan term(n) - in years and/or months

Goal: claculates and displays the monthly payments and balance of loan until the load is paid off. Known as "amortization schedule"

Monthly payments calculated using amortization equations: | M = P ((r(1+r)^n)/((1+r)^n)-1) | M = monthly payments, P is principal load, r is the monthly interest rate and n is the number of pauments over loan's lifetime.

r = (1+ (APR/100)^1/12) - 1

*/

//Pointers for the functions?? call by reference

void ValueInputer(int* p, double* apr, int* n);

void AprConverter(double apr);

void AmortizationCalculator(float p, double r, int n);

void InterestAndPrincipalCalculator();

void TotalPaymentsAndInterestAccumulator();

void DisplayTabularInformation();

int main(){
    int p = 0; // Loan Amount
    double apr = 0.00; //Annual Percentage Rate
    int n = 0; //Loan term in months

    ValueInputer(&p, &apr, &n);
    return 0;
}

void ValueInputer(int* p_ptr, double* apr_ptr, int* n_ptr){ 

    cout << "----- Input the following values -----" << endl;
   
    cout << "Loan Amount (P): ";
    cin >> *p_ptr;
    cout << *p_ptr;
    
    cout << "Annual Percentage Rate (APR): ";
    // cin >> apr;
   
    cout << "Loan Term \"in years\" (n): ";
    // cin >> n;

};
/*
ERROR: if non integer value is inputted program ends without trying to convert it. (SOLVE using pointers)
*/

void AprConverter(double apr);

void AmortizationCalculator(float p, double r, int n);

void InterestAndPrincipalCalculator();

void TotalPaymentsAndInterestAccumulator();

void DisplayTabularInformation();