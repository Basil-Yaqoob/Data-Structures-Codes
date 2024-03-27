#include <iostream>
using namespace std;
class Node {
public:
    int data, height;
    Node* right, * left;
    Node(int a) {
        data = a;
        height = 1;
        right = NULL;
        left = NULL;
    }
};
class AVL {
public:
    Node* root;
    AVL() {
        root = NULL;
    }
    int height(Node* root) {
        if (root == NULL)
            return 0;
        return root->height;
    }
    int Balance(Node* root) {
        return (root == NULL) ? 0 : (height(root->left) - height(root->right));
    }
    Node* LeftRotate(Node* root) {
        Node* y = root->right;
        Node* temp = y->left;
        y->left = root;
        root->right = temp;

        root->height = (max(height(root->left),height( root->right)) + 1);
        y->height = (max(height(y->left), height(y->right)) + 1);
        return y;
    }
    Node* RightRotate(Node* root) {
        Node* y = root->left; 
        Node* temp = y->right;
        y->right = root;
        root->left = temp;

        root->height = (max(height(root->left), height(root->right)) + 1);
        y->height = (max(height(y->left), height(y->right)) + 1);
        return y;
    }
    Node* Insert(Node* root,int a) {
        if (root == NULL) {
            return new Node(a);
        }
        if (a < root->data) {
            root->left = Insert(root->left, a);
        }
        else  if (a > root->data) {
            root->right = Insert(root->right, a);
        }
        else {
            return root;
        }
        root->height = (max(height(root->left), height(root->right)) + 1);
        int bal = Balance(root);

        //for LL case rotate RR
        if (bal > 1 && a < root->left->data)
            return RightRotate(root);

        //for RR case rotate LL
        if (bal < -1 && a > root->right->data)
            return LeftRotate(root);

        //for LR case rotate LL then RR
        if (bal > 1 && a > root->left->data) {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }

        //for RL case rotate RR then LL
        if (bal < -1 && a < root->right->data) {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }
        return root;
    }
    void InsertAVL(int a) {
        this->root = Insert(this->root, a);
    }
    void preOrder(Node* root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    int FindMax(Node* root) {
        if (root == NULL)
            return 0;
        while (root->right != NULL) {
            root = root->right;
        }
        return root->data;
    }
    Node* Delete(Node* root, int a) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == a) {
            //0 child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            //1 child
            //left child
            if (root->left != NULL && root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //right child
            if (root->left == NULL && root->right != NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            //2 child
            if (root->left != NULL && root->right != NULL) {
                int max = FindMax(root->left);
                root->data = max;
                root->left = Delete(root->left, max);
            }
        }
        else if (a < root->data) {
            root->left = Delete(root->left, a);
        }
        else if (a > root->data) {
            root->right = Delete(root->right, a);
        }
        //Now checking Balance
        root->height = (max(height(root->left),height(root->right)+1));
        int bal = Balance(root);
        if (bal >1 && Balance(root->left) >= 0) {
            return RightRotate(root);
        }
        if (bal > 1 && Balance(root->left) <= 0) {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }
        if (bal < -1 && Balance(root->right) <= 0) {
            return LeftRotate(root);
        }
        if (bal < -1 && Balance(root->right) >= 0) {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }
        return root;
    }
};
int main()
{
    AVL tree;
    tree.root = tree.Insert(tree.root, 10);
    tree.InsertAVL(9);
    tree.InsertAVL(5);
    tree.InsertAVL(10);
    tree.InsertAVL(0);
    tree.InsertAVL(6);
    tree.InsertAVL(11);
    tree.InsertAVL(-1);
    tree.InsertAVL(1);
    tree.InsertAVL(2);
    tree.preOrder(tree.root);
    tree.root = tree.Delete(tree.root, 10);
    cout << endl;
    tree.preOrder(tree.root);
}

//#include <iostream>
//using namespace std;
//class Node {
//public:
//	int data, height;
//	Node* right, * left;
//	Node(int a) {
//		data = a;
//		height = 1;
//		left = NULL;
//		right = NULL;
//	}
//};
//class AVL {
//public:
//	Node* root;
//	AVL() {
//		root = NULL;
//	}
//	int height(Node*root) {
//		return root->height;
//	}
//	int Balance(Node* root) {
//		return(root == NULL) ? 0 : (height(root->left) - height(root->right));
//	}
//	Node* LeftRotate(Node* root) {
//		Node* y = root;
//		Node* temp = y->left;
//		y->left = root;
//		root->right = temp;
//
//		root->height = (max(height(root->left), height(root->right)) + 1);
//		y->height = (max(height(y->left), height(y->right)) + 1);
//		return y;
//	}
//	Node* RightRotate(Node* root) {
//		Node* y = root;
//		Node* temp = y->right;
//		y->right = root;
//		root->left = temp;
//
//		root->height = (max(height(root->left), height(root->right)) + 1);
//		y->height = (max(height(y->left), height(y->right)) + 1);
//		return y;
//	}
//	Node* Insert(Node* root, int a) {
//		if (root == NULL) {
//			return new Node(a);
//		}
//		if (a < root->data) {
//			root->left = Insert(root->left, a);
//		}
//		if (a > root->data) {
//			root->right = Insert(root->right, a);
//		}
//		else {
//			return root;
//		}
//		root->height = (max(height(root->left), height(root->right) + 1));
//		int bal = Balance(root);
//		//LL to RR
//		if (bal > 1 && a < root->left->data) {
//			return RightRotate(root);
//		}
//		//LR to LL then RR
//		if (bal > 1 && a > root->left->data) {
//			root->left = LeftRotate(root->left);
//			return RightRotate(root);
//		}
//		//RR to LL
//		if (bal < -1 && a > root->left->data) {
//			return LeftRotate(root);
//		}
//		//RL to RR then LL
//		if (bal < -1 && a < root->left->data) {
//			root->right = LeftRotate(root->right);
//			return LeftRotate(root);
//		}
//		return root;
//	}
//	void InsertAVL(int a) {
//		this->root = Insert(this->root, a);
//	}
//	void preOrder(Node* root)
//	{
//		if (root != NULL)
//		{
//			cout << root->data << " ";
//			preOrder(root->left);
//			preOrder(root->right);
//		}
//	}
//	int FindMax(Node* root) {
//		if (root == NULL) {
//			return 0;
//		}
//		while (root->right != NULL) {
//			root = root->right;
//		}
//		return root->data;
//	}
//	Node* Delete(Node* root, int a) {
//		if (root == NULL) {
//			return NULL;
//		}
//		if (root->data == a) {
//			//0 Child
//			if (root->left == NULL && root->right == NULL) {
//				delete root;
//				return NULL;
//			}
//			//1 Child
//			//Left Child
//			if (root->left != NULL && root->right == NULL) {
//				Node* temp = root->left;
//				delete root;
//				return temp;
//			}
//			//Right Child
//			if (root->left == NULL && root->right != NULL) {
//				Node* temp = root->right;
//				delete root;
//				return temp;
//			}
//			// 2 Children
//			if (root->left != NULL && root->right != NULL) {
//				int max = FindMax(root->left);
//				root->data = max;
//				root->left = Delete(root->left, max);
//			}
//		}
//		else if (a < root->data) {
//			root->left = Delete(root->left, a);
//		}
//		else if (a > root->data) {
//			root->right = Delete(root->right, a);
//		}
//		root->height = (max(height(root->left), height(root->right)) + 1);
//		int bal = Balance(root);
//		if (bal > 1 && Balance(root->left) >= 0) {
//			return RightRotate(root);
//		}
//		if (bal > 1 && Balance(root->left) <= 0) {
//			root->left = LeftRotate(root->left);
//			return RightRotate(root);
//		}
//		if (bal < -1 && Balance(root->right) <= 0) {
//			return LeftRotate(root);
//		}
//		if (bal < -1 && Balance(root->right) >= 0) {
//			root->right = RightRotate(root->right);
//			return LeftRotate(root);
//		}
//		return root;
//	}
//};
//int main()
//{
//	AVL tree;
//	tree.root = tree.Insert(tree.root, 10);
//	tree.InsertAVL(9);
//	tree.InsertAVL(5);
//	tree.InsertAVL(10);
//	tree.InsertAVL(0);
//	tree.InsertAVL(6);
//	tree.InsertAVL(11);
//	tree.InsertAVL(-1);
//	tree.InsertAVL(1);
//	tree.InsertAVL(2);
//	tree.preOrder(tree.root);
//	tree.root = tree.Delete(tree.root, 10);
//	cout << endl;
//	tree.preOrder(tree.root);
//}