#include <iostream>
#include <climits> 
#include<stack>
using namespace std;

class Node1 {
public:
    int data;
    int weight;
    Node1() : data(0), weight(0) {}
    Node1(int a, int b) : data(a), weight(b) {}
};

void Heapify_Min(Node1** arr, int size, int index) {
    int smallest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if (leftChild <= size && arr[leftChild]->weight < arr[smallest]->weight) {
        smallest = leftChild;
    }
    if (rightChild <= size && arr[rightChild]->weight < arr[smallest]->weight) {
        smallest = rightChild;
    }
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        Heapify_Min(arr, size, smallest);
    }
}

class Priority_Queue {
public:
    Node1** arr;
    int size;

   
    Priority_Queue(int a) {
        size = 0;
        arr = new Node1 * [a];  // Increase array size by 1
    }

    void Push(int a, int b) {
        Node1* newNode = new Node1(a, b);
        arr[++size] = newNode;
        int ind = size;
        while (ind > 1 && arr[ind]->weight < arr[ind / 2]->weight) {
            swap(arr[ind], arr[ind / 2]);
            ind = ind / 2;
        }
    }

    int pop() {
        if (size == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }
        Node1* temp = arr[1];
        swap(arr[1], arr[size--]);
        Heapify_Min(arr, size, 1);
        return temp->data;
    }

    bool isEmpty() {
        return (size == 0) ? true : false;
    }
};

class Node {
public:
    int data;
    int weight;
    Node* next = NULL;
    Node(int a, int b) : data(a), weight(b), next(NULL) {}
};

class HashTable {
public:
    Node** table;
    int size;
    HashTable(int a) :size(a), table(new Node* [a] {}) {}

    void Insert(int x, int y, int w) {
        int value = x % size;
        Node* newNode = new Node(y, w);
        newNode->next = table[value];
        table[value] = newNode;
    }

    void Print() {
        for (int i = 0; i < size; i++) {
            cout << "Node " << i << " : ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->data << "," << temp->weight << ") , ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
        cout << endl;
    }
};

class Graph {
    HashTable* list;
    int vertices;
public:
    Graph(int a) :vertices(a), list(new HashTable(a)) {};

    void addEdge(int x, int y, int w) {
        list->Insert(x, y, w);
    }

    void Print() {
        list->Print();
    }

    void PrimsAlgorithm(int startingVertex) {
        int MST = 0;
        int* dis = new int[vertices];
        bool* visited = new bool[vertices] {false};
        for (int i = 0; i < vertices; i++) {
            dis[i] = INT_MAX;
        }
        Priority_Queue pq(vertices);
        pq.Push(startingVertex, 0);
        dis[startingVertex] = 0;

        while (!pq.isEmpty()) {
            int cur = pq.pop();
           
            Node* temp = list->table[cur];

            while (temp != NULL) {
                if ((!visited[temp->data]) && (temp->weight < dis[temp->data])) {
                    dis[temp->data] = temp->weight;
                    visited[temp->data] = true;
                    MST += temp->weight;
                    pq.Push(temp->data, temp->weight);
                }
                temp = temp->next;
            }
        }

        cout << "Minimum Spanning Tree Size is: " << MST << endl;
    }
};

int main() {
    Graph graph(5);

 
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 4 ,7);

    cout << "Adjacency List:\n";
    graph.Print();
    graph.PrimsAlgorithm(0);
}
