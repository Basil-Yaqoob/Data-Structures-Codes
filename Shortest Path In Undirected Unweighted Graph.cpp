#include <iostream>
using namespace std;
template<typename U>
class Stack {
public:
    class Nodes {
    public:
        U data;
        Nodes* next;
        Nodes(U a) :data(a), next(NULL) {}
    };
    Nodes* top;
    Stack() :top(NULL) {}
    void push(U a) {
        if (top == NULL) {
            top = new Nodes(a);
            return;
        }
        Nodes* temp = new Nodes(a);
        temp->next = top;
        top = temp;
    }
    U pop() {
        if (top == NULL) {
            return U();
        }
        Nodes* temp = top;
        top = top->next;
        return temp->data;
    }
    bool isEmpty() {
        return(top == NULL) ? true : false;
    }
};
template<typename T>
class Queue {
public:
    class node {
    public:
        T data;
        node* next;
        node(T a) :data(a), next(NULL) {}
    };
    node* rear;
    node* front;
    Queue() :rear(NULL), front(NULL) {}
    void push(T a) {
        if (front == NULL) {
            front = rear = new node(a);
            return;
        }
        node* temp = new node(a);
        rear->next = temp;
        rear = temp;
    }
    T pop() {
        if (front == NULL) {
            return T();
        }
        node* temp = front;
        front = front->next;
        return temp->data;
    }
    T getFront() {
        return front->data;
    }
    bool isEmpty() {
        return(front == NULL) ? true : false;
    }
};
class Node {
public:
    int data;
    Node* next = NULL;
    Node(int a) :data(a), next(NULL) {}
};
class HashTable {
public:
    Node** table;
    int size;
    HashTable(int a) :size(a), table(new Node* [a] {}) {}
    void Insert(int x, int y) {
        int value = x % size;
        Node* newNode = new Node(y);
        newNode->next = table[value];
        table[value] = newNode;
    }
    void PrintTable() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            cout << "Node " << i << " -> ";
            while (temp != NULL) {
                cout << temp->data << " , ";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << endl;
    }
};
class Graph {
    HashTable* list;
    int vertices;
public:
    Graph(int a) :vertices(a), list(new HashTable(a)) {};
    void addEdge(int x, int y, bool directed) {
        list->Insert(x, y);
        if (!directed) {
            list->Insert(y, x);
        }
    }
    void printAdjacenceyList() {
        list->PrintTable();
    }
    void ShortedPath(int src,int des) {
        bool* check = new bool[vertices] {false};
        int* parent = new int[vertices] {-1};
        Queue<int>bfs;
        bfs.push(src);
        check[src] = true;
        //parent already -1
        while (!bfs.isEmpty()) {
            int cur = bfs.getFront();
            bfs.pop();
            Node* temp = list->table[cur];
            while (temp != NULL) {
                if (!check[temp->data]) {
                    bfs.push(temp->data);
                    check[temp->data] = true;
                    parent[temp->data] = cur;
                }
                temp = temp->next;
            }
        }
        int current = des;
        Stack<int>shortestPath;
        shortestPath.push(current);
        while (current != src) {
            current = parent[current];
            shortestPath.push(current);
        }
        cout << "Shortest Path from " << src << " to " << des << " is : ";
        while (!shortestPath.isEmpty()) {
            cout << shortestPath.pop() << " -> ";
        }
        cout << endl;
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, false);
    //g.printAdjacenceyList();
    g.ShortedPath(0, 4);
}
