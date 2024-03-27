#include <iostream>
#include <climits> 
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
        arr = new Node1 * [a];
        for (int i = 0; i < size; i++) {
            arr[i] = new Node1;
        }
        size = 0;
    }

    // Push a new Node onto the priority queue
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
            return NULL;
        }
        Node1* temp = arr[1];
        swap(arr[1], arr[size--]);
        Heapify_Min(arr, size, 1);
        return temp->data;
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return (size == 0) ? true : false;
    }
};
class Node {
public:
    int data;
    int weight;
    Node* next = NULL;
    Node(int a, int b) :data(a), weight(b), next(NULL) {}
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
    void DijkstrasAlgorithm(int startingVertex) {
        int* dis = new int[vertices];
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

                if ((dis[cur] != INT_MAX) && (dis[cur] + temp->weight < dis[temp->data])) {
                    dis[temp->data] = dis[cur] + temp->weight;
                    pq.Push(temp->data, dis[temp->data]);
                }

                temp = temp->next;
            }
        }

        for (int i = 0; i < vertices; i++) {
            cout << dis[i] << " , ";
        }
    }

};

int main() {

    Graph graph(5);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 3, 3);
    graph.addEdge(3, 4, 5);
    cout << "Adjacency List:\n";
    graph.Print();
    graph.DijkstrasAlgorithm(0);
}
