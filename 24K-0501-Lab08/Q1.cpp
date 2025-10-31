#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string val = "") {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* head;

    Tree() {
        head = NULL;
    }

    Node* insert(string data, Node* head) {
        if (head == NULL) {
            head = new Node(data);
        }
        else if (data < head->data) {
            head->left = insert(data, head->left);
        }
        else if (data > head->data) {
            head->right = insert(data, head->right);
        }
        return head;
    }

    
    void inorder(Node* head) {
        if (head == NULL)
            return;

        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
};

int main() {
    Tree t;

    
    t.head = t.insert("Switzerland", t.head);
    t.head = t.insert("Tokyo", t.head);
    t.head = t.insert("Miami", t.head);
    t.head = t.insert("San Fransisco", t.head);
    t.head = t.insert("Murree", t.head);
    t.head = t.insert("New York", t.head);
    t.head = t.insert("New Zealand", t.head);

    
    cout << "Inorder Traversal: ";
    t.inorder(t.head);

    return 0;
}
