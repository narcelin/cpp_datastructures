#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr){}; //initalize node class
};

//LinkedList class representing a singly linked list
class LinkedList{
    private:
    Node* head;
    Node* tail;

    public:
    LinkedList(): head(nullptr), tail(nullptr){};

    //Insert an element at the beginning of the linked list
    void insertAtHead(int value){
        Node* newNode = new Node(value);
        newNode -> next = head;
        head = newNode;

        //If list was empty, update tail
        if(tail == nullptr){
            tail = newNode;
        }
    }

    //Intsert an element at the end of the linked list
    void insertAtTail(int value){
        Node* newNode = new Node(value);
        
        //If list was empty, set new Node as head & tail
        if(head == nullptr){
            head = tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    //delete a node from the beginning of the singly linked list
    void deleteAtHead(){
        if(head == nullptr){
            //nothing to delete
            return;
        } 

        Node* temp = head;
        head = head->next;
        delete temp;

        if(head == nullptr){
            tail = nullptr;
        }
    }

    //delete the last node in the singly linked list
    void deleteAtTail(){
        if(head == nullptr){
            return;
        }

        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }

        //traverse the list to get to the second to last node
        Node* current = head;
        while(current->next != tail){
            current = current->next;
        }
        delete tail;
        tail = current;
        current->next = nullptr;
    }

    //display the elements in the list
    void display(){
        Node* current = head;
        if(head == nullptr){
            cout << "The list is empty";
            return;
        }

        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
 
};

int main(){
    LinkedList myList;

    myList.insertAtHead(3);
    myList.insertAtHead(6);
    myList.insertAtHead(7);
    myList.insertAtHead(4);
    myList.insertAtHead(7);

    myList.display();

    myList.deleteAtHead();
    
    myList.display();

    myList.deleteAtTail();
    
    myList.display();

    myList.insertAtTail(55);
    
    myList.display();

    return 0;
}