#include <iostream>

using namespace std;

//push, pop, isEmpty, top, size etc..

const int capacity = 50; //Dont Do This

class Stack{
    private:
        int elements[capacity];
        size_t t;

    public:
        Stack() : t(-1) {}
        
        void Push(int newElement){
            if(t+1 < capacity){
                t++;
                elements[t] = newElement;
            } else {
                cout << "Stack Overflow!" << endl;
            }
        };;

        int Pop(){
            if(t >= 0){
                return elements[t--]; //does this pop t then decrement it?? (YES) 33:19 Jan 26 video
            } else {
                cout << "Stack is empty" << endl;
                return -1;
            }
        };;

        int Top(){
            if(t >= 0){
                return elements[t];
            } else {
                cout << "Stack is empty" << endl;
                return -1;
            }
        };;

        int size(){
            return t+1;
        };;

        bool isEmpty(){
            return t == -1;
        };;
};


int main(){
    string input_string;
    cout << "Input String: ";
    cin >> input_string;

    if(input_string == ""){
        cout << "Empty String" << endl;
    };  

    Stack myInputStack;

    for(int i = 0; i < input_string.length(); i++){
        cout << input_string[i] << endl;
        myInputStack.Push(input_string[i]);
    };

    for(int i = 0; i < myInputStack.size(); i++){
        cout << "size" << i << endl;
    };

    cout << myInputStack.Top();

    return 0;
}

