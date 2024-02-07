#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


void CastingVariables();
int RandomIntGenerator(int min, int max);


int main() {
    //CastingVariables();
    cout << RandomIntGenerator(0,100);
    return 0;
}


void CastingVariables(){


    //type casting temporarly changes the memory for the variable for that line of code and then changes it back.
    //For example:
    int x = 3;
    int y = 2;
    cout << "Double: " << (double)x/y << endl; //This example allows the computer to properly divide these two 
    cout << "Int: "<< x/y << endl;
}

int RandomIntGenerator(int min, int max){
    srand(time(0));
    return (rand() % max) + min;
};

