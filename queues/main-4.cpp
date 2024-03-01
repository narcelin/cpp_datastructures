#include <iostream>

class CircularQueue {
private:
    int f; // front
    int size;
    int N; // capacity

public:
    int* array;
    int r; // rear
    CircularQueue(int N) : N(N) {
        array = new int[N];
        f = r = -1;
        size = 0;
    }
    ~CircularQueue() {
        delete[] array;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == N;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            f = r = 0;
            array[r] = value;
        } else {
            array[r] = value;
            r = (r + 1) % N;
        }

        size++;
    }

   int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // Return error value
        }
        int dequeuedValue = array[f];
        if (f == r) {
            f = r = -1;
        } else {
            f = (f + 1) % N;
        }
        
        size--;
        return dequeuedValue;
    }
    
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot peek.\n";
            return -1; // Error value
        }
        return array[f];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        int i = f;
        std::cout << "Queue: ";
        while (i != r) {
            std::cout << array[i] << " ";
            i = (i + 1) % N;
        }
        std::cout << array[r] << std::endl;
    }
};

int main() {
    CircularQueue queue(10);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display(); // Should print: 1 2 3 4 5
    
    std::cout << "Dequeued Element: " << queue.dequeue() << std::endl; // Should print: 1
    queue.dequeue(); // Remove 2

    queue.enqueue(6);
    queue.enqueue(7);

    queue.display(); // Should print: 3 4 5 6 7

    std::cout << "Front element: " << queue.peek() << std::endl; // Should print: 3

    std::cout << queue.array[queue.r]<< " "<<queue.r << std::endl;

    return 0;
}
