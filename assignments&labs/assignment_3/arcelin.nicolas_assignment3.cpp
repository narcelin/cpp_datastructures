#include <iostream>
#include <array>
#include <fstream>

using namespace std;

int Random_Number_Generator(int min, int max);

void Random_Grades_Generator(ofstream& fileOut, int maximum_points);

void averageCalculator(ifstream& fileIn2, ofstream& fileOut, string line, int lineNumber);

int main(){
    srand(time(NULL));

    //Could change to ask user to input names
    string students[] = {"Doe, John", "Smith, Adam", "Randal, Bob", "Delony, Danny", "Cooly, Carly", "Genuis, Gina", "Chapelle, Dave", "Jackson, Michael", "Sleepy, Adam", "Duck, Donald", "END_OF_ARRAY"};

    ofstream fileOut("example.txt");

    if(!fileOut) {
        cout << "Unable to create file" << endl;
        return 1;
    }

    for(int i = 0; students[i] != "END_OF_ARRAY"; i++){
        fileOut << students[i] << " ";
        Random_Grades_Generator(fileOut, 20);
    } 
        
    fileOut.close();

    ofstream newFileOut("students_with_average.txt", ios::app);
    ifstream fileIn("example.txt");
    ifstream fileIn2("example.txt");

    string line;
    int lineNumber = 1;
    while(getline(fileIn, line)){
        // cout << "LINE : " << line << endl;
        averageCalculator(fileIn2, newFileOut, line, lineNumber);
        lineNumber++;
    }
    
    // cout << line;

    fileIn.close();

    return 0;
}

int Random_Number_Generator(int min, int max){
    return rand()%(max-min + 1) + min;
};

void Random_Grades_Generator(ofstream& fileOut, int maximum_points){
    int quizzes_taken = Random_Number_Generator(0, 20);
    for(int i = 0; i < 20; i++){
        if(i <= quizzes_taken){
            fileOut << Random_Number_Generator(0, maximum_points) << " ";
        } else {
            fileOut << 0 << " ";
        }
    }
    fileOut << endl;
};

//Input grade[] = {Maximum possible points on one exam * -1 , exam grade 1, exam grade 2, etc...}
void averageCalculator(ifstream& fileIn2, ofstream& newFileOut, string line, int lineNumber){
    
    int total_sum = 0;

    fileIn2.seekg(0);
    string line2;
    for(int i = 1 ; i < lineNumber; i++){
        getline(fileIn2, line2);
    }

    //Skips last and first name
    fileIn2.ignore(256, ' ');
    fileIn2.ignore(256, ' ');

    for(int i = 0; i < 20; i++){
        int temp;
        fileIn2 >> temp;
        cout << "TEMP: " << temp << endl;
        // cout << "Grade " << i << ": " << temp << endl;
        total_sum += temp;
    }
    // cout << "total sum: " << total_sum << endl;
    double average_grade = total_sum / 400.00 * 100;

    // line += average_grade;
    newFileOut << line << average_grade << endl;
};