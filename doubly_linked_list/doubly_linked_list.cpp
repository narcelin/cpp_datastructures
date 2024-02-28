#include <iostream>

// Node class represents each element in the linked list
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
    Node* tail;

    public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}; //head(nullptr) same idea as head = nullptr?

    void insertAtHead(int value){
        Node* newNode = new Node(value);
        newNode -> next = head;
        newNode -> prev = nullptr;

        if (head != nullptr) {
            head -> prev = newNode;
        }
        head = newNode;

        if (tail == nullptr){
            tail = newNode;
        }
    };

    void insertAtTail(int value){
        Node* newNode = new Node(value);
        newNode -> prev = tail;
        newNode -> next = nullptr;

        if(tail != nullptr){
            tail -> next = newNode;
        }
        tail = newNode;
        if(head == nullptr){
            head = newNode;
        };
    }

    void insertAfter(Node* prevNode, int value){
        if(prevNode == nullptr){
            return; //Node does not exist
        };

        Node* newNode = new Node(value);
        newNode -> prev = prevNode;
        newNode -> next = prevNode -> next;

        if(prevNode -> next != nullptr){
            prevNode -> next -> prev = newNode;
        } else {
            tail = newNode;
        }
        prevNode -> next = newNode;
    }

    void deleteNode(Node* nodeToDelete){
        if(nodeToDelete == nullptr){
            return; //NodeToDelete does not exist
        };

        // if(nodeToDelete -> next == nullptr){
        //     tail = nodeToDelete -> prev;
        //     nodeToDelete -> prev -> next = nullptr;
        //     return;
        // } TAIL???

        nodeToDelete -> prev -> next = nodeToDelete -> next;
        nodeToDelete -> next -> prev = nodeToDelete -> prev;

        delete nodeToDelete;



    }
   
};

int main(){
    return 0;
}