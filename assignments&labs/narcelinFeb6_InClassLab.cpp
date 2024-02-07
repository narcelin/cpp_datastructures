#include <iostream>
#include <cmath> 


using namespace std;

int get_input(string question);
void hat_size(int weight, int height);
void jacket_size(int height, int weight, int age);
void waist_size(int weight, int age);
void ten_years_later(int height, int weight, int age);

int main(){
    while(true){
        int user_height = get_input("Please input your height: ");
        int user_weight = get_input("Please input your weight: ");
        int user_age = get_input("Please input your age: ");

        hat_size(user_height, user_weight);
        jacket_size(user_height, user_weight, user_age);
        waist_size(user_weight, user_age);
        ten_years_later(user_height, user_weight, user_age);

        int keep_going = get_input("Would you like to continue? 1 for yes, 0 for no.");
        if(keep_going != 1) {
            exit(1);
        } 
    }
}

int get_input(string question){
    cout << question << endl;
    int return_variable;
    cin >> return_variable;
    return return_variable;
};

void hat_size(int height, int weight){
    double hat_size = 2.9 * (weight / height);
    int hat_size_int_part = (int) hat_size;
    double hat_size_decimal_part = round(8 * (hat_size - hat_size_int_part)) / 8.0; //decimal rounded to the nierest eighth (1/8th)
    cout << hat_size_decimal_part << endl; 
    hat_size = hat_size_int_part + hat_size_decimal_part;
    cout << "Your hat size is: " << hat_size << endl;
}

void jacket_size(int height, int weight, int age){
    double jacket_size = height * weight / 288.0;

    if(age >= 40){
        jacket_size += 0.125 * ((age - 30) / 10);
    }

    int jacket_size_rounded = round(jacket_size);

    cout << "Your jacket size is: " << jacket_size_rounded << endl;
};

void waist_size(int weight, int age){
    double waist_size = weight / 5.7;

    if(age >= 30){
        waist_size += 0.1 * ((age - 28) / 2);
    }

    int waist_size_rounded = (int) waist_size + 1; // Or ceil(waist_size). Casting always rounds down

    cout << "Your waist size is: " << waist_size_rounded << endl;
};

void ten_years_later(int height, int weight, int age){
    cout << "10 years later... " << endl;
    hat_size(height, weight);
    jacket_size(height, weight, age + 10);
    waist_size(weight, age + 10);

};

