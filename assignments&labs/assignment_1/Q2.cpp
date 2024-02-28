/* 
Assignment 1: Q2 for Data Struct & Algorithm Analysis
Author: Nicolas Arcelin Ovando
Date: Feb 15, 2024
Q2: Using Doubly linked list, reverse the integers. (No tail pointer)
*/
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList{
    private:
    Node* head;

    public:
    DoublyLinkedList() : head(nullptr) {};

    void insertAtHead(int value){
        Node* newNode = new Node(value);
        newNode -> next = head;
        newNode -> prev = nullptr;

        if (head != nullptr) {
            head -> prev = newNode;
        }
        head = newNode;
    };

    void printValues(){
        Node* currentNode = head;
        do{
        cout << currentNode -> data << " ";
        currentNode = currentNode -> next;
        } while (currentNode != nullptr);
        cout << endl;
    }

    void reverse(){
        if(head == nullptr){
            cout << "Doubly Linked List Is Empty." << endl;
            return;
        };

        Node* currentNode = head;
        Node* nextNode = nullptr;  // Initialize nextNode to nullptr
        Node* prevNode = nullptr;

        while (currentNode != nullptr) {
            nextNode = currentNode -> next;  // Store the next node
            currentNode -> prev = nextNode;  // Update the prev pointer to the next node
            currentNode -> next = prevNode;  // Update the next pointer to the previous node (or nullptr if it's the last node)
            prevNode = currentNode;        // Move prevNode to the current node
            currentNode = nextNode;        // Move currentNode to the next node
        }

        // Update head to point to the last node (which is now the first node after reversal)
        head = prevNode;
    };
};

int main(){
    int input_array[5] = {25, 40, 6, 43, 2}; //Input

    DoublyLinkedList integers;

    int i = sizeof(input_array) / sizeof(input_array[0]); //Length of array
    do{
        integers.insertAtHead(input_array[i - 1]); //Creating input DoublyLinkedList. Note insert at head which needed decrementing i
        i--; 
    } while (i > 0);
    integers.printValues(); //Print values in order
    integers.reverse(); // Reverse Doubly Linked List
    integers.printValues(); 
    return 0;
}