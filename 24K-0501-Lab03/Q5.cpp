#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string data;
        Node* next;

        Node() : data(""), next(NULL) {}
        Node(string val): data(val), next(NULL){}

};

class PlaylistManager{
    public:
        Node* head;
        Node* tail;

        PlaylistManager() : head(NULL), tail(NULL) {}

        void addAtEnd(string val) {
            Node* n = new Node(val);
            if (head == NULL) {
                head = n;
                n->next = head;
                tail = n;
                cout << val << " added at end" << endl;
                return;
            }

            
            tail->next = n;
            n->next = head;
           tail = n;
            cout << val << " added at end" << endl;
        }

        void displayInfo() {
            Node *temp = head;
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            do {
                cout << temp->data << " -> ";
                temp = temp->next;
            } while (temp != head);
            cout << "(replaying the playlist from the start: " << head->data << ")" << endl<<endl;
        }

        void deleteFromEnd() {
            if (head == NULL) {
                cout << "Linked List is empty" << endl;
                return;
            }
            string val = tail->data;

            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                temp->next = head;
                delete tail;
                tail = temp;
            }
            cout << val << " deleted from end" << endl;
        }


};



int main() {
    PlaylistManager pm;
    pm.addAtEnd("Song A");
    pm.addAtEnd("Song B");
    pm.addAtEnd("Song C");
    pm.addAtEnd("Song D");
    cout << "Current Playlist:"<< endl;
    pm.displayInfo();

    cout << "Deleting last song from the playlist." << endl;
    pm.deleteFromEnd();
    cout << "Updated Playlist:"<< endl;
    pm.displayInfo();

    return 0;
}
