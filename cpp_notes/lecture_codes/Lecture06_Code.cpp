/*
COP3014
Lecture 06: Functions, call by value, library functions
Instructor: Sareh Taebi, PhD
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

const double PI = 3.14159;          //global variable! All functions can use it

double total_cost(int number_par, double price_par);   //function declaration, necessary!
//Computes the total cost, including 5% sales tax,
//on number_par items at a cost of price_par each.

double area (double radius);
//Returns the area of a circle with the specified radius.

double volume(double radius);
//Returns the volume of a sphere with the specified radius.

using namespace std;

int main()
{
    //sample use of random number generators
    cout << "#################PROGRAM 0##############" << endl;

    srand(time(0));    //call the srand function only once at the beginning, the seed is
                       // the time in seconds
    for (int i = 0; i< 100; i++)
        cout << "die roll :" << (rand() % 6) + 1 << endl <<endl;


    //program that allows us to practice call-by-value functions

    double price, bill;
    int number;
    cout << "#################PROGRAM I##############" << endl;

    cout << "Enter the number of items purchased: ";
    cin >> number;
    cout << "Enter the price per item $";
    cin >> price;

    bill = total_cost(number, price);     //function call


    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << number << " items at "
    << "$" << price << " each.\n"
    << "Final bill, including tax, is $" << bill
    << endl << endl;


    //another problem to practice functions
    double radius_of_both, area_of_circle, volume_of_sphere;
    cout << "#################PROGRAM II##############" << endl;
    cout << "Enter a radius to use for both a circle\n"
    << "and a sphere (in inches): ";
    cin >> radius_of_both;

    area_of_circle = area(radius_of_both);
    volume_of_sphere = volume(radius_of_both);

    cout << "Radius = " << radius_of_both << " inches\n"
    << "Area of circle = " << area_of_circle
    << " square inches\n"
    << "Volume of sphere = " << volume_of_sphere
    << " cubic inches\n";


    return 0;
}

//function definition
double total_cost(int number_par, double price_par)   //number_par and price_par are local to the function
{
    const double TAX_RATE = 0.07; //7% sales tax      //local constant
    double subtotal;

    subtotal = price_par * number_par;
    return (subtotal + subtotal * TAX_RATE);   //return one single value or return a big expression
}

double area(double radius)
{
    return (PI * pow(radius, 2));
}

double volume(double radius)
{
    return ((4.0/3.0) * PI * pow(radius, 3));
}

