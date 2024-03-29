#include <iostream>
#include <vector>

using namespace std;

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
            return;
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
        int index = key % 8;

        
        //TODO: check if there is anything at the computed index
        if(!arraylist_1[index]){
            cout << "Nothing to remove" << endl;
            return;
        } else {
            cout << "Node found with key: " << key << " Found" << endl;
            
            //Loops unti located node with key
            Node* currentNode = arraylist_1[index];
            Node* prevNode;
            bool isHead = true;
            while(currentNode -> key != key && currentNode != nullptr){
                if(isHead) isHead = false;
                prevNode = currentNode;
                currentNode = currentNode -> next;
            }
 
            //If node we are looking for is at the head
            if(isHead) {
                arraylist_1[index] = currentNode -> next;
            } else{
                prevNode -> next = currentNode -> next;
                cout << "Deleting KEY: " << currentNode -> key << " VALUE: " << currentNode -> value << endl;
            }
                delete currentNode;
        }

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
    Node* test = new Node(50, 5);

    //Finding Conflicts in hash function
    // for(int i = 0; i < 50; i ++){
    //     for(int x = 0; x < 50; x++){
    //     if(i%8 == x%8){
    //         cout << "CONFLICT AT " << i << " & " << x << endl;
    //     }
    //     }
    // }

    //test your code with a series of insertion and removal operations
    list.insertWithHash(0, 20);
    list.insertWithHash(8, 20);
    list.insertWithHash(16, 20);
    list.insertWithHash(24, 20);
    list.insertWithHash(32, 20);
    list.insertWithHash(40, 20);
    list.display();

    list.remove(24);
    list.display();

    return 0;
}
