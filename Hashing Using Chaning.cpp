#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* next;
    Node(int a) :value(a), next(NULL) {}
};
class HashTable {
    Node** table;
    int size;
    int currentSize;
public:
    HashTable(int a) :size(a), table(new Node* [size] {0}), currentSize(0) {}
    int HashFunction(int value) {
        return value % size;
    }
    void rehash() {
        Node** newTable = new Node * [size * 2] {0};
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                int key = temp->value % (size * 2);
                if (newTable[key] == NULL) {
                    newTable[key] = new Node(temp->value);
                }
                else {
                    Node* newNode = new Node(temp->value);
                    newNode->next = newTable[key];
                    newTable[key] = newNode;
                }
                temp = temp->next;
            }
        }

        delete[]table;
        table = newTable;
        size *= 2;
    }
    void insert(int val) {
        int key = HashFunction(val);
        if (table[key] == NULL) {
            table[key] = new Node(val);
            currentSize++;
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = table[key];
        table[key] = newNode;
        currentSize++;
        if (static_cast<float>(currentSize) / size > 0.7) {
            rehash();
        }
    }
    void Search(int val) {
        int key = HashFunction(val);
        Node* temp = table[key];
        if (temp == NULL) {
            cout << "Value Not Found.\n";
            return;
        }
        while (temp != NULL) {
            if (temp->value == val) {
                cout << "Value is Found.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Value Not Found.\n";
        return;
    }
    void Delete(int val) {
        int key = HashFunction(val);
        Node* current = table[key];
        Node* previous = NULL;

        while (current != NULL) {
            if (current->value == val) {
                if (previous == NULL) {
                    table[key] = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                currentSize--;
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Value Not Found.\n";
    }
    void Print() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            cout << "Index: " << i << " | ";
            while (temp != NULL) {
                cout << temp->value << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
        cout << endl;
    }

};
int main()
{
    HashTable h1(10);
    h1.insert(9);
    h1.insert(20);
    h1.insert(5);
    h1.insert(10);
    h1.insert(26);
    h1.insert(52);
    h1.insert(11);
    h1.insert(24);
    h1.insert(53);
    h1.insert(17);
    h1.insert(28);
    h1.insert(54);
    h1.insert(18);
    h1.insert(25);
    h1.insert(56);
    h1.insert(13);
    h1.insert(7);
    h1.insert(72);



    /*
    //h1.Print();
    h1.Search(10);
    h1.Search(20);
    h1.Search(5);
    h1.Search(60);
    h1.Delete(20);
    //h1.Print();
    h1.Delete(60);
    */
    h1.Print();
}
