#include <iostream>
#include <array>
#include <fstream>

using namespace std;

int Random_Number_Generator(int min, int max);

void Random_Grades_Generator(int student_grades[]);

double averageCalculator(int grades[], int quiz_max_points);

int main(){
    srand(time(NULL));

    // ofstream outFS("example.txt");

    // if(!outFS) {
    //     cout << "Unable to create file" << endl;
    //     return 1;
    // }
    // outFS << "Hello, World" << endl;
    // outFS.close();
    

    // int intArray1[12] = {-20, 20, 18, 19, 16, 15, 18, 19, 12, 14, 10};
    // int intArray2[12] = {-20, 20, 18, 12, 14, 10};
    // int intArray3[12] = {-20, 20, 18, 12, 14, 10};
    // averageCalculator(intArray1);
    // cout << Random_Number_Generator(0, 10);
    int student_grades[11];
    Random_Grades_Generator(student_grades);
    double averageStudentGrade = averageCalculator(student_grades, 20);

    cout << "AVG " << averageStudentGrade << endl;
    
    return 0;
}

int Random_Number_Generator(int min, int max){
    return rand()%(max-min + 1) + min;
};

void Random_Grades_Generator(int student_grades[]){
    int quizzes_taken = Random_Number_Generator(0, 10);
    // cout << "QUIZZEZ TAKEN: " << quizzes_taken << endl;
    // int quizzes_taken = 5;

    for(int i = 0; i < 10; i++){
        if(i <= quizzes_taken){
        student_grades[i] = Random_Number_Generator(0, 20);
        } else {
            student_grades[i] = 0;
            // cout << "ELSE RAN" << endl;
        }
    }

    for(int i = 0; i < 10; i++){
        cout << student_grades[i] << " ";
    }
        cout << endl; 

};

//Input grade[] = {Maximum possible points on one exam * -1 , exam grade 1, exam grade 2, etc...}
double averageCalculator(int grade[], int quiz_max_points){
    int num_of_grades = 0;
    int sum_of_grades = 0;
    
    //Sums all grades and get a value of total exams taken. grade[0] = Value of each exam
    for(int i = 0; i < 10; i++){ 
        // cout << i << endl;
        num_of_grades++;
        if(grade[i] != 0){
        sum_of_grades += grade[i];
        cout << i << ": "<< grade[i] << endl;
        } 
    }

    //grade[0] = max points / exam
    //max points is inserted as a negative for insurance hence the (* -1).
    int total_possible_points = num_of_grades * quiz_max_points; 

    cout << endl << "Total possible points: " << total_possible_points << endl;
    cout << num_of_grades << endl;
    cout << sum_of_grades / num_of_grades << endl;
    
    double gradeAvg = total_possible_points / num_of_grades;

    return gradeAvg;
};