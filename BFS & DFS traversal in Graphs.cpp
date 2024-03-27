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
        Nodes*temp= new Nodes(a);
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
    Node* next;
    Node(int a) :data(a) {
        next = NULL;
    }
};
class HashTable {
public:
    Node** table;
    int size;

    HashTable(int a):size(a),table(new Node*[a]()){}
    void Insert(int x,int y) {
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
                cout << temp->data << ",";
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
    Graph(int a) :vertices(a), list(new HashTable(a)){}
    void addEdge(int x, int y, bool directed) {
        list->Insert(x, y);
        if (!directed) {
            list->Insert(y, x);
        }
    }
    void Print() {
        list->PrintTable();
    }
    void BFS(int startingVertex) {
        bool* check = new bool[vertices] {false};
        Queue<int>bfs;
        bfs.push(startingVertex);
        check[startingVertex] = true;
        while (!bfs.isEmpty()) {
            int currentVertex = bfs.getFront();
            cout << currentVertex << " ";
            bfs.pop();
            Node* temp = list->table[currentVertex];
            while (temp != NULL) {
                if (!check[temp->data]) {
                    bfs.push(temp->data);
                    check[temp->data] = true;
                }
                temp = temp->next;
            }
        }
    }
    void DFS(int startingVertex) {
        bool* check = new bool[vertices] {false};
        Stack<int>dfs;
        dfs.push(startingVertex);
        check[startingVertex] = true;
        while (!dfs.isEmpty()) {
            int cur = dfs.pop();
            cout << cur << " ";
            Node* temp = list->table[cur];
            while (temp != NULL) {
                if (!check[temp->data]) {
                    dfs.push(temp->data);
                    check[temp->data] = true;
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    Graph g1(5);
    g1.addEdge(0, 1, false);
    g1.addEdge(1, 2, false);
    g1.addEdge(2, 3, false);
    g1.addEdge(3, 1, false);
    g1.addEdge(3, 4, false);
    g1.addEdge(0, 4, false);
    g1.Print();
    g1.BFS(0);
    cout << endl;
    g1.DFS(0); 
}
