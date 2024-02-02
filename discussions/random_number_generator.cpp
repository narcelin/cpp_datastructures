#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void RandomFloatingNumberGenerator(); // Random float Between 1 and 10

int main(){
    // RandomFloatingNumberGenerator();

    char char_array[45];
    cin >> char_array;

    for(int i = 0; char_array[i] != '\0'; i++){
        cout << char_array[i];
    };
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