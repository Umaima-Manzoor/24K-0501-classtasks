#include <iostream>
#include <string>
using namespace std;


class Node {
    public:
        string data;
        Node* next;

        Node(string val) : data(val), next(NULL) {}
};

class Library {
    public:
        Node* head;
        Node* tail;

        Library(): head(NULL), tail(NULL) {}

        void addAtFront(string val) {
            Node* n = new Node(val);
            n->next = head;
            head = n;
            cout << val << " added at front" << endl;
            
        }

        void addAtEnd(string val) {
            Node* n = new Node(val);
            if (head == NULL) {
                head = n;
                cout << val << " added at end" << endl;
                return;
            }
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;

            }
            temp->next = n;
            n->next = tail;
            cout << val << " added at end" << endl;
        }

        void addAtPosition(string val, int pos) {
            Node* n = new Node(val);
            Node *current;
            Node *previous;
            current = head;
            for (int i=0; i<pos; i++){
                previous = current;
                current = current->next;
            }
            previous->next = n;
            n->next = current;
            cout << val << " added at position " << pos << endl;
        }

        void search(string val) {
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
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        }

    };


int main() {

    Library books;

    books.addAtEnd("Data Structures");
    books.addAtEnd("Operating Systems");
    books.addAtEnd("Computer Networks");
    books.addAtEnd("Database Systems");

    books.addAtFront("Artifical Intelligence");
    books.addAtEnd("Machine Learning");
    books.addAtPosition("Cyber Security", 3);

    books.search("Database Systems");
    books.displayInfo();
    return 0;
}
