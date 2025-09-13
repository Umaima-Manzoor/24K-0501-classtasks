#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node() : data(0), next(NULL), prev(NULL) {}
        Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class Railway {
    public:
    Node* head;
    Node* tail;

    Railway() : head(NULL), tail(NULL) {}

    void AddAtEnd(int val) {
        Node *n = new Node(val);
        if (tail == NULL) {
            head = n;
            tail = n;
        
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void deleteFromFront() {
        int val = head->data;
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
        cout << val << " deleted from front" << endl;
        
    }

    void searchByNumber(int val) {
        Node* temp = head;
        while(temp != NULL) {
            if (temp->data == val) {
                cout << val << " found in the linked list" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << val << " not found in the linked list" << endl;
    }

    void displayInfo() {
        Node *temp = head;
        while (temp != NULL ){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        
    }
};

int main () {
    Railway r;
    r.AddAtEnd(101);
    r.AddAtEnd(102);
    r.AddAtEnd(103);


    r.displayInfo();
    cout << endl;

    r.deleteFromFront();

    r.displayInfo();
    cout << endl;

    r.searchByNumber(102);
    

    return 0;
}
