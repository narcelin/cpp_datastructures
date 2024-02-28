#include <iostream>

using namespace std;



class Node{
    public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr){}
};

//LinkedList class representing a single linked list
class LinkedList{
  private:
  Node* head;
  Node* tail;
  
  public:
  LinkedList(): head(nullptr), tail(nullptr){}

  //Insert an element at the beginning of the Linked List
  void insertAtHead(int value){
    Node* newNode = new Node(value);
    newNode -> next = head;
  };

  void insertAtTail(int value){
    Node* newNode = new Node(value);
    

  }
};

int main(){
    int max = 21;
    int min = 10;
    cout << rand()%(max-min + 1) + min;
    return 0;
}