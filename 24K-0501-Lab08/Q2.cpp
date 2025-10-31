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

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    
    int countNodes(Node* node) {
        if (node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    
    int countLeafNodes(Node* node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

    
    int height(Node* node) {
        if (node == NULL) return -1;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    Tree tree;
    int n, val;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i+1 << ": ";
        cin >> val;
        tree.root = tree.insert(tree.root, val);
    }

    cout << endl;
    cout << "Total number of nodes: " << tree.countNodes(tree.root) << endl;
    cout << "Total number of leaf nodes: " << tree.countLeafNodes(tree.root) << endl;
    cout << "Height of the tree: " << tree.height(tree.root) << endl;

    return 0;
}
