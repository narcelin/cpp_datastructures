/* 
Assignment 1: Q1 for Data Struct & Algorithm Analysis
Author: Nicolas Arcelin Ovando
Date: Feb 15, 2024
Q1: Using Stack implementations, remove repeated string values from the input.
*/
#include <iostream>
#include <cstring>
#include <array>

using namespace std;

// Dont do this
const int capacity = 50; 

class Stack{
    private:
        char elements[capacity];
        size_t t;

    public:
        Stack() : t(-1) {}

        void Push(char newElement){
            if(t+1 < capacity){
                t++;
                elements[t] = newElement;
            } else {
                cout << "Stack Overflow!" << endl;
            }
        };

        char Pop(){
            if(t >= 0){
                return elements[t--];
            } else {
                cout << "Stack is empty" << endl;
                return -1;
            }
        };

        char Top(){
            if(t >= 0){
                return elements[t];
            } else {
                cout << "Stack is empty" << endl;
                return -1;
            }
        };

        int size(){
            return t+1;
        };

        bool isEmpty(){
            return t == -1;
        };
};



int main(){
    string input_string;
    cout << "Input String: ";
    cin >> input_string;
    int input_string_length = input_string.length();

    Stack inputStack;
    Stack outputStack;

    for(int i = 0; i < input_string_length; i++){ // Creates a Stack out of the input
        inputStack.Push(input_string[i]);
    };  
    
    for(int i = 0; i <= input_string_length; i++){ //Transfer onto output stack and checks for repeated values
        char transfer_char = inputStack.Pop();
        if(outputStack.Top() != transfer_char){
            outputStack.Push(transfer_char);
        } else {
            outputStack.Pop();
        }
    };

    if(outputStack.size() <= 1){ //On Empty outputStack
        cout << "Empty String" << endl;
        exit(0);
    }; 

    int output_stack_szie = outputStack.size();
    for(int i = 0; i <= output_stack_szie; i++){ //Prints outputStack. Note that it will also remove values from outputStack.
        cout << outputStack.Pop();
    }
 
    return 0;
};