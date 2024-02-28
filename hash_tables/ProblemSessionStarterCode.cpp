#include <iostream>
#include <vector>

// Node class represents each element in the linked list
class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class ArrayList {
private:
    std::vector<Node*> arraylist_1;  // std::vector to store linked lists

public:
    ArrayList() {
        // Initialize the array list with 8 elements, all initialized to nullptr
        arraylist_1.resize(8, nullptr);
    }

    // Insert an element using a hash function (key mod 8)
    void insertWithHash(int key, int value) {
        //TODO: compute the index
        int index = key % 8;
        
        //TODO: if nothing is there add the node at the computed location
        if(!arraylist_1[index]){
            arraylist_1[index] = new Node(key, value);
        } else {
            Node* currentNode = arraylist_1[index];
            while(currentNode -> next != nullptr){
                currentNode = currentNode -> next;
            }
            currentNode -> next = new Node(key, value);
        }
        //TODO: if there is a collision, traverse the linked list and add the new node at the end

        

    }

    // Delete a specific node with a given key using hash function
    void remove(int key) {
        //TODO: compute the index

        
        //TODO: check if there is anything at the computed index

        //TODO: find the node with the specified key 
        //Note: make sure to handle cases where it is at the head and in the middle of the list
        
        //TODO: update the pointers correctly
        
        //TODO: Delete the Node

    }
    
    // Display the elements of the array list
    void display() {
        std::cout << "Array List: ";
        for (int i = 0; i < arraylist_1.size(); ++i) {
            Node* current = arraylist_1[i];
            while (current != nullptr) {
                std::cout << "(" << current->key << "," << current->value << ") ";
                current = current->next;
            }
            std::cout << "| "; // Separate linked lists with a pipe symbol
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~ArrayList() {
        for (int i = 0; i < arraylist_1.size(); ++i) {
            Node* current = arraylist_1[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    ArrayList list;  // Create an array list 

    //test your code with a series of insertion and removal operations
    list.insertWithHash(36, 20);
    list.display();

    list.insertWithHash(22, 43);
    list.display();

    return 0;
}
