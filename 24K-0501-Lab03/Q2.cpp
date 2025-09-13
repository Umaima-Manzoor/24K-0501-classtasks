#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string data;
        Node* next;

        Node(string d): data(d), next(NULL){}

};

class Catalog {
    public:
        Node *head;
        Node *tail;

        Catalog() : head(NULL), tail(NULL) {}

        void AddAtEnd(string val) {
            Node *n = new Node(val);
            if (head == NULL) {
                head = n;
                tail = n;
                return;
            }

            else {
                Node *temp = head;
                while (temp->next!=NULL) {
                    temp = temp->next;
                }
                temp->next = n;
                tail = n;
            }
        }

        void displayInfo() {
            Node *temp = head;
            while (temp != NULL ){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        }

        void deleteFromFront() {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void searchByTitle(string val) {
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

       void searchByPosition(int pos) {
            Node *temp = head;
            for (int i=0; i<pos; i++){
                temp = temp->next;
            }
            cout << "Book at position " << pos << " is " << temp->data << endl;
       }
};

int main() {
    Catalog c;
    c.AddAtEnd("Data Structures");
    c.AddAtEnd("Operating Systems");
    c.AddAtEnd("Computer Networks");
    c.AddAtEnd("Database Systems");

    c.displayInfo();
    cout << endl;

    c.deleteFromFront();
    c.displayInfo();
    cout << endl;
    c.searchByTitle("Database Systems");
    c.searchByPosition(1);

}
