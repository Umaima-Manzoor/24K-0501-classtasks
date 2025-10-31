#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int val = 0) {
        id = val;
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

    Node* insert(int id, Node* head) {
        if (head == NULL) {
            head = new Node(id);
        }
        else if (id < head->id) {
            head->left = insert(id, head->left);
        }
        else if (id > head->id) {
            head->right = insert(id, head->right);
        }
        return head;
    }

    void inorder(Node* head) {
        if (head == NULL)
            return;
        inorder(head->left);
        cout << head->id << " ";
        inorder(head->right);
    }

    
    bool exists(Node* head, int id) {
        if (head == NULL) return false;
        if (id == head->id) return true;
        if (id < head->id) return exists(head->left, id);
        return exists(head->right, id);
    }

    Node* findLCA(Node* head, int emp1, int emp2) {
        if (head == NULL)
            return NULL;
        
            
        if (!exists(head, emp1) || !exists(head, emp2)) {
            return NULL;
        }
        
        if (emp1 < head->id && emp2 < head->id)
            return findLCA(head->left, emp1, emp2);
        if (emp1 > head->id && emp2 > head->id)
            return findLCA(head->right, emp1, emp2);
        return head;
    }
};

int main() {
    Tree t;

    t.head = t.insert(50, t.head);
    t.head = t.insert(30, t.head);
    t.head = t.insert(70, t.head);
    t.head = t.insert(20, t.head);
    t.head = t.insert(40, t.head);
    t.head = t.insert(60, t.head);
    t.head = t.insert(80, t.head);

    cout << "Employee Hierarchy (Inorder Traversal): ";
    t.inorder(t.head);
    cout << endl;

    int emp1, emp2;
    cout << "Enter first employee ID: ";
    cin >> emp1;
    cout << "Enter second employee ID: ";
    cin >> emp2;

    Node* manager = t.findLCA(t.head, emp1, emp2);

    if (manager != NULL)
        cout << "Closest Common Manager (LCA) of Employee " << emp1 << " and " << emp2 << " is Employee " << manager->id << "." << endl;
    else
        cout << "No common manager found. One or both employee IDs do not exist in the hierarchy." << endl;

    return 0;
}
