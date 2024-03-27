#include <iostream>
using namespace std;

void HeapifyMax(int* arr, int size, int index) {
    int largest = index;
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;
    if (leftChild <= size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild <= size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(arr[largest], arr[index]);
        HeapifyMax(arr, size, largest);
    }
}

class Priority_Queue {
    int* arr;
    int size;
public:
    Priority_Queue(int capacity) : arr(new int[capacity + 1]), size(0) {
        arr[0] = -1;
    }
    void push(int element) {
        arr[++size] = element;
        int index = size;
        while (index > 1 && arr[index] > arr[index / 2]) {
            swap(arr[index], arr[index / 2]);
            index = index / 2;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
        }

        int top = arr[1];
        arr[1] = arr[size--];
        HeapifyMax(arr, size, 1);
        return top;
    }

    bool isEmpty() {
        return size == 0;
    }

    void Print() {
        cout << "Priority Queue size: " << size << ", elements: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Priority_Queue p1(100);
    p1.push(35);
    p1.push(40);
    p1.push(45);
    p1.push(30);
    p1.Print();
    p1.pop();
    p1.Print();

    return 0;
}
