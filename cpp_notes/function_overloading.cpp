/*
We can use two different functions with the same exact name.
*/

#include <iostream>

using namespace std;

void functionX(int intValue);
void functionX(char charValue);
void functionX(int intValue, char charValue);

int main(){
    int value1 = 0;
    char value2 = 'c';


    functionX(value1);
    functionX(value2);
    functionX(value1, value2); 

    return 0;
}

void functionX(int intValue){
    cout << "Fuction 1 Ran" << endl;
};

void functionX(char charValue){   
    cout << "Fuction 2 Ran" << endl;
};

void functionX(int intValue, char charValue){
    cout << "Fuction 3 Ran" << endl;
};
