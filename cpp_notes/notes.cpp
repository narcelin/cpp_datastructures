#include <iostream>
using namespace std;

void CastingVariables();

int main() {
    //CastingVariables();
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