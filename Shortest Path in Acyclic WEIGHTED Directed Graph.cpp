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
    int weight;
    Node* next = NULL;
    Node(int a, int b) :data(a), weight(b), next(NULL) {}
};
class HashTable {
public:
    Node** table;
    int size;
    HashTable(int a) :size(a), table(new Node* [a] {}) {}
    void Insert(int x, int y,int w) {
        int value = x % size;
        Node* newNode = new Node(y,w);
        newNode->next = table[value];
        table[value] = newNode;
    }
    void PrintTable() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            int j = 0;
            cout << "Node " << i << " -> ";
            Stack<int>data;
            Stack<int>weight;
            while (temp != NULL) {
                data.push(temp->data);
                weight.push(temp->weight);
                temp = temp->next;
                j++;
            }
            while (j != 0) {
                cout <<"("<< data.pop() << " , "<<weight.pop()<<"),";
           
                j--;
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
    void addEdge(int x, int y, int w) {
        list->Insert(x, y,w);
        
    }
    void printAdjacenceyList() {
        list->PrintTable();
    }
    void DFSUtil(int startingVertex, bool* check, Stack<int>&dfs) {
        check[startingVertex] = true;
        Node* temp = list->table[startingVertex];
        while (temp != NULL) {
            if (!check[temp->data]) {
                DFSUtil(temp->data,check,dfs);
            }
            temp = temp->next;
        }
        dfs.push(startingVertex);
    }
    void ShortedPath() {
        bool* check = new bool[vertices] {false};
        Stack<int>dfs;
        for (int i = 0; i < vertices; i++) {
            if (!check[i]) {
                DFSUtil(i, check, dfs);
            }
        }
        int* dis = new int[vertices];
        for (int i = 0; i < vertices; i++) {
            dis[i] = INT_MAX;
        }
        dis[0] = 0;
      

        while (!dfs.isEmpty()) {
            int top = dfs.pop();
            Node* temp = list->table[top];
            while (temp != NULL) {
                if (dis[top] != INT_MAX) {
                    if ((dis[top] + temp->weight) < dis[temp->data]) {
                        dis[temp->data] = dis[top] + temp->weight;
                    }
                }
                temp = temp->next;
            }
        }
        cout << "Shortest Path is: ";
        for (int i = 0; i < vertices; i++) {
            cout << dis[i] << " -> ";
        }
        cout << endl;
    }
};
int main()
{
    Graph g(6); // Change the number of vertices as needed
    g.addEdge(0, 1,  5);
    g.addEdge(0, 2,  3);
    g.addEdge(1, 2,  2);
    g.addEdge(1, 3,  6);
    g.addEdge(2, 3,  7);
    g.addEdge(2, 4,  4);
    g.addEdge(2, 5,  2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.printAdjacenceyList();
    g.ShortedPath();
}
