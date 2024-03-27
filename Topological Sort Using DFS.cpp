// Topological Sort Using DFS
// It is a Linear Ordering of Vertices such that if a vertex is u-v then U always comes before V
//Because of this it is only valid for Directed Acyclic Graph DAG
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
    void addEdge(int x, int y) {
        list->Insert(x, y);
    }
    void printAdjacenceyList() {
        list->PrintTable();
    }
    void DFS(int startingVertex, bool* check, Stack<int>& dfs) {
        check[startingVertex] = true;
        Node* temp = list->table[startingVertex];
        while (temp != NULL) {
            if (!check[temp->data]) {
                DFS(temp->data, check, dfs);
            }
            temp = temp->next;
        }
        dfs.push(startingVertex);
    }

    void TopologicalSort() {
        Stack<int> dfs;
        bool* check = new bool[vertices] {false};
        for (int i = 0; i < vertices; i++) {
            if (!check[i]) {
                DFS(i, check, dfs);
            }
        }
        cout << "Topological Sort is : ";
        while (!dfs.isEmpty()) {
            cout << dfs.pop() << " ";
        }
        cout << endl;
    }
};
int main()
{
    Graph g(7); 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(3, 6);
    g.printAdjacenceyList();
    cout << endl;
    g.TopologicalSort();
}
