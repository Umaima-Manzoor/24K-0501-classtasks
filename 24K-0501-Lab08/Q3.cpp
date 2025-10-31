#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    
    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }

        
        if (node->left == NULL) {
            node->left = insert(node->left, val);
        } else if (node->right == NULL) {
            node->right = insert(node->right, val);
        } else {
            
            node->left = insert(node->left, val);
        }
        return node;
    }

    
    bool isFull(Node* node) {
        if (node == NULL) return true; 
        if ((node->left == NULL && node->right == NULL)) return true; 
        if (node->left != NULL && node->right != NULL) {
            return isFull(node->left) && isFull(node->right);
        }
        return false; 
    }
};

int main() {
    Tree tree;
    int n, val;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        tree.root = tree.insert(tree.root, val);
    }
    cout << endl;
    if (tree.isFull(tree.root)) {
        cout << "The tree is a Full Binary Tree." << endl;
    } else {
        cout << "The tree is NOT a Full Binary Tree." << endl;
    }

    return 0;
}
