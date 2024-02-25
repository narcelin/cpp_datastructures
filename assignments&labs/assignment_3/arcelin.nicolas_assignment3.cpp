#include <iostream>
#include <array>
#include <fstream>

using namespace std;

int Random_Number_Generator(int min, int max);

void Random_Grades_Generator(ofstream& fileOut, int maximum_points);

void studentFileOutput(ifstream& fileIn2, ofstream& fileOut, string line, int lineNumber);

int main(){
    //Creates random grades for students
    srand(time(NULL));

    string students[] = {"Doe, John", "Smith, Adam", "Randal, Bob", "Delony, Danny", "Cooly, Carly", "Genuis, Gina", "Chapelle, Dave", "Jackson, Michael", "Sleepy, Adam", "Duck, Donald", "END_OF_ARRAY"};

    ofstream fileOut("students_without_averages.txt");

    if(!fileOut) {
        cout << "Unable to create file" << endl;
        return 1;
    }

    for(int i = 0; students[i] != "END_OF_ARRAY"; i++){
        fileOut << students[i] << " ";
        Random_Grades_Generator(fileOut, 20);
    } 
        
    fileOut.close();

    

    //Having issues with the pointer so I set two separate input streams for the file in.
    ofstream newFileOut("students_with_averages.txt", ios::app);
    ifstream fileIn("students_without_averages.txt");
    ifstream fileIn2("students_without_averages.txt");

    string line;
    int lineNumber = 1; //Helper to change line pointer
    while(getline(fileIn, line)){
        studentFileOutput(fileIn2, newFileOut, line, lineNumber);
        lineNumber++;
    }
    
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

void studentFileOutput(ifstream& fileIn2, ofstream& newFileOut, string line, int lineNumber){
    
    int total_sum = 0;

    //So I was having a really hard time with this. Decided to keep this because it was working. This is to change the inputFile ptr line.
    //Personally will find a better way to do this
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
        total_sum += temp;
    }
    double average_grade = total_sum / 400.00 * 100;

    newFileOut << line << average_grade << endl;
};