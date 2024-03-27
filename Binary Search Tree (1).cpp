#include <iostream>
using namespace std;

template<typename T>
class Queue {
public:
    class Node1 {
    public:
        T data;
        Node1* next;
        Node1(T a) {
            data = a;
            next = NULL;
        }
    };
    Node1* rear;
    Node1* front;
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void push(T a) {
        if (front == NULL) {
            front = rear = new Node1(a);
            return;
        }
        Node1* temp = new Node1(a);
        rear->next = temp;
        rear = temp;
    }
    T pop() {
        if (front == NULL) {
            return T();
        }
        Node1* temp = front;
        T a = temp->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return a;
    }
    T getFront() {
        if (front == NULL) {
            return T();
        }
        return front->data;
    }
    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }
};

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int a) {
        data = a;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    void Insert(int a) {
        root = InsertRecursive(root, a);
    }

    Node* InsertRecursive(Node* node, int a) {
        if (node == NULL) {
            return new Node(a);
        }
        if (a > node->data) {
            node->right = InsertRecursive(node->right, a);
        }
        else if (a < node->data) {
            node->left = InsertRecursive(node->left, a);
        }
        return node;
    }

    void LevelOrder() {
        if (root == NULL) {
            cout << "Tree is Empty\n";
            return;
        }
        Queue<Node*> q;
        q.push(root);
        while (!q.isEmpty()) {
            Node* temp = q.getFront();
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
    void PreOrder(Node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << "\t";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    void InOrder(Node* root) {
        if (root == NULL) {
            return;
        }
        InOrder(root->left);
        cout << root->data << "\t";
        InOrder(root->right);
    }
    void PostOrder(Node* root) {
        if (root == NULL) {
            return;
        }
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << "\t";
    }
    bool search(Node*root,int a) {
        if (root == NULL) {
            return false;
        }
        if (root->data == a) {
            return true;
        }
        bool left = search(root->left,a);
        bool right = search(root->right,a);
        return left || right;
    }
    int FindMax(Node* root) {
        if (root == NULL) {
            return -1;
        }
        while (root->right != NULL) {
            root = root->right;
        }
        return root->data;
    }
    Node* del(Node* root, int a) {
        if (root == NULL) {
            cout << "Tree is Empty\n";
            return root;
        }
        if(a==root->data){
        //0 child
            if (root->right == NULL && root->left == NULL) {
                delete root;
                return NULL;
            }
        //1 child
            //  Left Child
            if (root->right == NULL && root->left != NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //  Right Child
            if (root->right != NULL && root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
        //2 children
            if (root->right != NULL && root->left != NULL) {
                int max = FindMax(root->left);
                root->data = max;
                root->left = del(root->left, max);
                return root;
            }
        }
        if (a < root->data) {
            root->left = del(root->left, a);
            return root;
        }
        if (a > root->data) {
            root->right = del(root->right, a);
            return root;
        }
       
    }
    void deletefromBst(int a) {
        this->root = del(this->root, a);
    }
    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return (1 + max(left, right));
    }
    int diameter(Node* root) {
        if (root == NULL) {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        return max(max(ld, rd), (lh + rh + 1));
    }
    bool isBalanced(Node* root) {
        if (root == NULL) {
            return true;
        }
        if (isBalanced(root->left)==false) {
            return false;
        }
        if (isBalanced(root->right) == false) {
            return false;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if (abs(lh - rh) <= 1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isIdentical(Node* r1, Node* r2) {
        if (r1 == NULL && r2 == NULL) {
            return true;
        }
        if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL) {
            return false;
        }
        if (r1 != NULL && r2 != NULL) {
            if (r1->data != r2->data) {
                return false;
            }
            return isIdentical(r1->right, r2->right) && isIdentical(r1->left, r2->left);
        }
    }
    bool isSumTree(Node* root) {
        int sum = 0;
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        bool LS = false;
        bool RS = false;
        if (root->left) {
            LS = isSumTree(root->left);
        }
        if (root->right) {
            RS = isSumTree(root->right);
        }
        return LS && RS && (root->data == (root->left->data + root->right->data));
    }
};

int main() {
    BST t1,t2;
    t1.Insert(10);
    t1.Insert(5);
    t1.Insert(5);
    t1.Insert(2);
    t1.Insert(3);
    t1.Insert(2);
    t1.Insert(3);
   /* t1.LevelOrder();
    t1.PreOrder(t1.root);
    cout << endl; 
    t1.InOrder(t1.root);
    cout << endl;
    t1.PostOrder(t1.root);
    cout << endl;
    if (t1.search(t1.root, 10)) {
        cout << "Node Found\n";
    }
    else {
        cout << "Node Not Found\n";
    }
    t1.deletefromBst(12);
    t1.LevelOrder();
    cout << "Height:" << t1.height(t1.root) << endl;
    cout << "Diameter:" << t1.diameter(t1.root) << endl;*/
    if (t1.isIdentical(t1.root,t2.root)) {
        cout << "Identical\n";
    }
    else {
        cout << "Not Identical\n";
    }
    if (t1.isSumTree(t1.root)) {
        cout << "Sum Tree\n";
    }
    else {
        cout << "Not a Sum Tree\n";
    }
    return 0;
}
