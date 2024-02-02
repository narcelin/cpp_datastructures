#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int Seeder(long long program_start_time, int cycle);
//Create a value for the srand() function to absorb. This will help with randomization

int main(){

    int user_input;
    int changing_seeder = 0;

   do{
    changing_seeder += 47;

    cout << "Run program press 1. Press any other key to exit" << endl;
    cin >> user_input;

    cout << time(NULL) << endl;


    // cout << time(NULL)/changing_seeder << endl;

    // srand(time(NULL)%changing_seeder);

    // float min = 13;
    // float max = 27.345;

    // int rand_factor = rand() - RAND_MAX;
    // cout << "rand(): "<< (double)rand() << endl;
    // cout << "RAND_MAX: " << (double)RAND_MAX << endl;
    // cout << "rand_factor: " << rand_factor << endl;

    // float range_difference = max - min;
    // cout << range_difference * rand_factor << endl;
   } while (user_input == 1);

    cout << "*** PROGRAM END ***" << endl;
   
return 0;
}

Seeder(long long program_start_time, int cycle){
    
};