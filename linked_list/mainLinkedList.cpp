#include <iostream>

// Node class represents each element in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class represents the singly linked list
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Insert a new element at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;

        // If the list was empty, update the tail
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    // Insert a new element at the tail of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value);

        // If the list is empty, update both head and tail
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete the first element in the list
    void deleteAtHead() {
        if (head == nullptr) {
            // List is empty, nothing to delete
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        // If the list is now empty, update the tail
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // Delete the last element in the list
    void deleteAtTail() {
        if (head == nullptr) {
            // List is empty, nothing to delete
            return;
        }

        if (head == tail) {
            // Only one node in the list
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    // Display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList myList;

    myList.insertAtHead(3);
    myList.insertAtHead(7);
    myList.insertAtHead(1);
    myList.insertAtHead(9);

    std::cout << "Original List: ";
    myList.display();

    myList.insertAtTail(5);
    myList.insertAtTail(2);

    std::cout << "List after insert at tail: ";
    myList.display();

    myList.deleteAtHead();

    std::cout << "List after delete at head: ";
    myList.display();

    myList.deleteAtTail();

    std::cout << "List after delete at tail: ";
    myList.display();

    return 0;
}