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
        int index = key % 8;
        if (arraylist_1[index] == nullptr) {
            arraylist_1[index] = new Node(key, value);
        } else {
            Node* current = arraylist_1[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(key, value);
        }
    }

    // Delete a specific node with a given key using hash function
    void remove(int key) {
        int index = key % 8;
        
        if (arraylist_1[index] == nullptr) {
            std::cout << "Node with key " << key << " not found!" << std::endl;
            return;
        }

        Node* current = arraylist_1[index];
        Node* prev;
        
        if (current->key ==key) {
            arraylist_1[index] = current->next; // Node to be removed is the head
        } 
        else {

            while (current != nullptr && current->key != key) {
                prev = current; // keep track of the previous node so we can reconnect the list after deleting
                current = current->next;
             }

            if (current == nullptr) {
                std::cout << "Node with key " << key << " not found!" << std::endl;
                return;
             }
        prev->next = current->next;
        delete current;
        std::cout << "Node with key " << key << " removed successfully!" << std::endl;
        }
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

    // Perform operations on the array list using hash functions
    // Example operations:
    list.insertWithHash(0, 5);         // Insert key 0, value 5
    list.display();            // Display the array list
        
    list.insertWithHash(19, 100); // Insert key 19, value 100 with hash function (11 mod 8)
    list.display();            // Display the array list
    
    list.insertWithHash(11, 8); // Insert key 11, value 8 with hash function (11 mod 8)
    list.display();            // Display the array list
    
    list.insertWithHash(3, 15); // Insert key 3, value 15 with hash function (3 mod 8)
    list.display();            // Display the array list
    
    list.insertWithHash(8, 25); // Insert key 8, value 25 with hash function (3 mod 8)
    list.display();            // Display the array list
    
    list.insertWithHash(9, 48); // Insert key 9, value 48 with hash function (3 mod 8)
    list.display();            // Display the array list
        
    list.remove(11);            // Remove element with key 11
    list.display();            // Display the array list

    return 0;
}
