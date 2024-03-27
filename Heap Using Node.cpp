#include <iostream>
using namespace std;
template<typename T>
class Queue {
public:
    class Node {
    public:
        Node* next;
        T data;
        Node(T a) : data(a), next(NULL) {}
    };
    Node* rear;
    Node* front;
    Queue() : rear(NULL), front(NULL) {}
    void push(T a) {
        if (front == NULL) {
            front = rear = new Node(a);
        }
        Node* temp = new Node(a);
        rear->next = temp;
        rear = temp;
    }
    T pop() {
        if (front == NULL) {
            cout << "Queue is Empty! ";
            return T();
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;         
        }
        return temp->data;
    }
    T getFront() {
        return front->data;
    }
    bool isEmpty() {
        return(front == NULL && rear == NULL) ? true : false;
    }
};
class NODE {
public:
    int data;
    NODE* left;
    NODE* right;
    NODE* parent;
    NODE(int a) :data(a), left(NULL), right(NULL), parent(NULL) {}

};
class HEAP {
public:
    NODE* root;
    HEAP() :root(NULL) {}
    void SwapNodes(NODE*& a, NODE*& b) {
        a->parent = b->parent;
        b->parent = a;
        if (b->left != a) {
            a->left = b->left;
        }
        else {
            a -> left = b;
        }
        if (b->right != a) {
            a->right = b->right;
        }
        else {
            a->right = b;
        }
        b->left = NULL;
        b->right = NULL;
    }
    void HeapifyMAXUp(NODE* child) {
        NODE* Parent = child->parent;
        if (child == NULL || Parent == NULL) {
            return;
        }
        if (child->data > Parent->data) {
            SwapNodes(child, Parent);
            HeapifyMAXUp(Parent);
        }
    }
    void Insert(int a) {
        if (root == NULL) {
            root = new NODE(a);
        }
        Queue<NODE*>q;
        q.push(root);
        while (!q.isEmpty()) {
            NODE* temp = q.getFront();
            q.pop();
            if (temp->left == NULL) {
                temp->left = new NODE(a);
                temp->left->parent = temp;
                HeapifyMAXUp(temp->left);
                break;
            }
            else {
                q.push(temp->left);
            }
            if (temp->right == NULL) {
                temp->right = new NODE(a);
                temp->right->parent = temp;
                HeapifyMAXUp(temp->right);
                break;
            }
            else {
                q.push(temp->right);
            }
        }
        
    }
    void LevelOrderTraversal() {
        if (root == NULL) {
            cout << "Tree is Empty\n";
            return;
        }
        Queue<NODE*>q;
        q.push(root);
        while (!q.isEmpty()) {
            NODE* temp = q.getFront();
            cout << temp->data << "\t";
            q.pop();

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
    
};
int main()
{
    HEAP h1;
    h1.Insert(50);
    h1.Insert(55);
    h1.Insert(53);
    h1.Insert(52);
    h1.Insert(54);
    h1.LevelOrderTraversal();
}
