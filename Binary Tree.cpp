#include <iostream>
using namespace std;
template<typename T>
class Queue {
    class Node {
    public:
        T data;
        Node* next;
        Node(T a) {
            data = a;
            next = NULL;
        }
    };
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
}
    void push(T a) {
        if (front == NULL) {
            front = rear = new Node(a);
            return;
        }
        Node* temp = new Node(a);
        rear->next = temp;
        rear = temp;
    }
    T pop() {
        if (front == NULL) {
            return T();
        }
        Node* temp = front;
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
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a) {
        data = a;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() {
        root = NULL;
    }
    void InsertNode(int a) {
        if (root == NULL) {
            root = new TreeNode(a);
            return;
        }
        Queue <TreeNode*> q;
        q.push(root);
        while (!q.isEmpty()) {
            TreeNode* temp = q.getFront();
            q.pop();
            if (temp->left == NULL) {
                temp->left = new TreeNode(a);
                return;
            }
            else {
                q.push(temp->left);
            }
            if (temp->right == NULL) {
                temp->right = new TreeNode(a);
                return;
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
        Queue<TreeNode*>q;
        q.push(root);
        while (!q.isEmpty()) {
            TreeNode* temp = q.getFront();
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
    bool search(TreeNode* root, int a) {
        if (root == NULL) {
            return false;
        }
        if (root->data == a) {
            return true;
        }
        bool foundLeft = search(root->left, a);
        bool foundRight = search(root->right, a);
        return foundLeft || foundRight;
    }
    void PreOrder(TreeNode* root) {
        if (root == NULL)
            return;
        cout << root->data << "\t";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    void PostOrder(TreeNode* root) {
        if (root == NULL)
            return;
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << "\t";
    } 
    void InOrder(TreeNode* root) {
        if (root == NULL)
            return;
        InOrder(root->left);
        cout << root->data << "\t";
        InOrder(root->right);
    }
    int NoOfLeafNode(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
            return 1;
        int left = NoOfLeafNode(root->left);
        int right = NoOfLeafNode(root->right);
        return left + right;
    }
};
int main()
{
    BinaryTree t1;
    t1.InsertNode(1);
    t1.InsertNode(2);
    t1.InsertNode(3);
    t1.InsertNode(4);
    t1.InsertNode(5);
    t1.InsertNode(6);
    t1.InsertNode(7);
    t1.LevelOrderTraversal();
    if (t1.search(t1.root, 7)) {
        cout << "Node found\n";
    }
    else {
        cout << "Node Not Found\n";
    }
    t1.PreOrder(t1.root);
    cout << endl;
    t1.InOrder(t1.root);
    cout << endl;
    t1.PostOrder(t1.root);
    cout << endl;
    cout << "Number of Leaf Nodes: " << t1.NoOfLeafNode(t1.root) << endl;
}
