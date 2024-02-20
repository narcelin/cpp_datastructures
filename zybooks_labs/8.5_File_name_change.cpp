/*
    File in ifstream example with string replacement
*/

#include <iostream>
#include <cstring>
#include <fstream>

// Include any necessary libraries here.

using namespace std;

int main() {
   
   /* Type your code here. */
   ifstream inFS;
   
   string directoryName;
   cin >> directoryName; 
    
   inFS.open("./"+directoryName);
   
   if(!inFS.is_open()){
      cout << "Error opening file" << endl;
      return 1;
      };
      
   string fileName;
   string strToReplace = "_photo.jpg";
   inFS >> fileName;
   
   while(!inFS.fail()){
      size_t strToReplaceIndex = fileName.find(strToReplace); //give fist index
      
      fileName.replace(strToReplaceIndex, strToReplace.length(), "_info.txt");
      
      cout << fileName << endl;
      
      inFS >> fileName;
      
      };

   return 0;
}
