#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void RandomFloatingNumberGenerator(); // Random float BETWEEN 0 and 3.40282347e+38

int main(){
    // RandomFloatingNumberGenerator();
    float floattt = 3.40282347e+38; // MAX FLOAT INPUT

    char user_float_input[46];
    cin >> user_float_input; //User input float number
    int decimals_index = 0;
    int user_inputs_length = 0;

    //Issue. If user starts with a decimal input ERROR
    for(int i = 0; user_float_input[i] != '.' && i != 47; i++){ //Locates decimal in the users input
        decimals_index += 1;
    };

    for(int i = 0; user_float_input[i] != '\0'; i++){
            user_inputs_length += 1;
    }; cout << "Users Input Length: " << user_inputs_length << endl; //Includes decimal. Should I remove it and rename this variable? Or is that knowlege intuitive.


    if(decimals_index == 47){ // Decimal does not exist.
        decimals_index = -1;
    } else { //If decimal exists get right and left lengths
        int left_of_decimal_length = decimals_index;
        int right_of_decimal_length = 0;
    }
    
    return 0;
}

void RandomFloatingNumberGenerator(){
    srand(time(0));

    string random_float = "";
    int rand_int = (rand() % 10) + 1; //Random int 1 - 10;
    random_float = to_string(rand_int);
    random_float += "."; //Adds decimal

    for(int i = 0; i != 7; i++ ){ //Create a random int between 1 - 9 then concates it to the end of the string
        int rand_int = (rand() % 9) + 1;
        random_float += to_string(rand_int);
    }

    cout << random_float;
};