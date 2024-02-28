#include <iostream>

using namespace std;

//que, deque, front, size, isEmpty

//Exceptions

//Queue as a linked list. Add new queue elements to the tail.

//Can use an array in a circular fashion 

class CircularQueue{
    private:
        int* array;
        int f; //array front
        int r; //array rear
        int size;
        int N; //capacity

    public:
        CircularQueue(int N) : N(N) {
            array = new int[N];
            f = r = -1;
            size = 0; //(N-f+r) mod N
        }
        ~CircularQueue() {
            delete[] array;
        }
};

int main(){
    return 0;
}