#include <iostream>

using namespace std;

void get_age(int& ref_age);

void swap(int& num1, int& num2);
void order(int& num1, int& num2);

int main(){
    int age = 27;
    get_age(age);

    int num1 = 10;
    int num2 = 5;

    swap(num1, num2);
    cout << num1 << " " << num2 << endl;

    order(num1, num2);
    cout << num1 << " " << num2 << endl;

    return 1;
}

void get_age(int& ref_age){
    ref_age = 45; //This is in mains scope
    cout << ref_age << endl;
}

void swap(int& num1, int& num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
};

void order(int& num1, int& num2){
    if(num2 > num1){
        swap(num1, num2);
    };
}