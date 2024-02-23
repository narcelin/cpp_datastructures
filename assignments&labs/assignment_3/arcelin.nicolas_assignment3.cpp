#include <iostream>
#include <array>

using namespace std;

int Random_Number_Generator(int initialInt, int finalInt);

double averageCalculator(int grades[]);

int main(){
    int intArray1[12] = {-20, 20, 18, 19, 16, 15, 18, 19, 12, 14, 10};
    int intArray2[12] = {-20, 20, 18, 12, 14, 10};
    int intArray3[12] = {-20, 20, 18, 12, 14, 10};
    averageCalculator(intArray1);
    
    return 0;
}

int Random_Number_Generator(int initialInt, int finalInt){
    //Create a random number generator between initialInt and finalInt
    
    return -1;
};

double averageCalculator(int grade[]){
    int num_of_grades;
    int sum_of_grades = 0;
    
    //Sums all grades and get a value of total exams taken. grade[0] = Value of each exam
    for(int i = 1; grade[i] != '\0'; i++){ 
        num_of_grades++;
        sum_of_grades += grade[i];
        cout << i << ": "<< grade[i] << endl;
    }

    //grade[0] = max points / exam
    //max points is inserted as a negative for insurance hence the (* -1).
    int total_possible_points = num_of_grades * grade[0] * -1; 

    cout << total_possible_points;
    
    return -1;
};