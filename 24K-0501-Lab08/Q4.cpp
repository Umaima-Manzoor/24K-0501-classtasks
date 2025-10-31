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

    
    Node* buildTree(int arr[], int i, int n) {
        if (i >= n) return NULL;
        Node* node = new Node(arr[i]);
        node->left = buildTree(arr, 2 * i + 1, n);
        node->right = buildTree(arr, 2 * i + 2, n);
        return node;
    }

    
    int subtreeSum(Node* node) {
        if (node == NULL) return 0;
        return node->data + subtreeSum(node->left) + subtreeSum(node->right);
    }

    
    bool findSubtreeWithSum(Node* node, int target, Node*& subtreeRoot) {
        if (node == NULL) return false;

        int sum = subtreeSum(node);
        if (sum == target) {
            subtreeRoot = node;
            return true;
        }

        return findSubtreeWithSum(node->left, target, subtreeRoot) ||
               findSubtreeWithSum(node->right, target, subtreeRoot);
    }

    
    void printSubtree(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        printSubtree(node->left);
        printSubtree(node->right);
    }
};

int main() {
    Tree tree;
    int n;

    cout << "Enter number of nodes in the complete binary tree: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> arr[i];
    }

    tree.root = tree.buildTree(arr, 0, n);

    int target;
    cout << "Enter target sum to find in a subtree: ";
    cin >> target;

    Node* subtreeRoot = NULL;
    if (tree.findSubtreeWithSum(tree.root, target, subtreeRoot)) {
        cout << "Subtree with sum " << target << " found. Preorder traversal of subtree: ";
        tree.printSubtree(subtreeRoot);
        cout << endl;
    } else {
        cout << "No subtree with sum " << target << " found." << endl;
    }

    delete[] arr;
    return 0;
}
