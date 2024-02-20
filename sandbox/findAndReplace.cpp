#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "The quick brown fox jumps over the lazy dog";

    cout << str << endl;

    string substr = "fox";
    
    size_t substr_index = str.find(substr);

    str.replace(substr_index, substr.length(), "cats");

    cout << str << endl;
    return 0;
};