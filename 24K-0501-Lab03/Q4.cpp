#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val): data(val), next(NULL){}

};

class LinkedList {
    public:
        Node* head;
        Node* tail;

        LinkedList() : head(NULL), tail(NULL) {}

        
        void addAtEnd(int val) {
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

        void displayInfo() {
            Node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        }

        void sort() {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            else {
                Node* temp = head;
                Node* index = NULL;
                int val;

                while (temp != NULL) {
                    index = temp->next;

                    while (index != NULL) {
                        if (temp->data > index->data) {
                            val = temp->data;
                            temp->data = index->data;
                            index->data = val;
                        }
                        index = index->next;
                    }
                    temp = temp->next;
                }
            }
        }

        void concatenate(LinkedList &other) {
            if (head == NULL) {
                head = other.head;
                return;
            }
            if (other.head == NULL) {
                return;
            }
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = other.head;
        }

        void findMiddleElement() {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }

            Node* slow = head;
            Node* fast = head;

            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << "Middle element is: " << slow->data << endl;

        }

        void removeDuplicates() {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            sort();
            Node* temp = head;
            while (temp->next != NULL) {
                if (temp->data == temp->next->data) {
                    Node* del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                }
                else {
                    temp = temp->next;
                }
            }

        }

        void mergeSorted(LinkedList &other) {
            
            sort();
            other.sort();
            
            Node* p1 = head;
            Node* p2 = other.head;

            LinkedList merged;
            
            if (head == NULL) {
                head = other.head;
                return;
            }
            if (other.head == NULL) {
                return;
            }

            



            while (p1 != NULL && p2 != NULL) {
                if (p1->data < p2->data) {
                    merged.addAtEnd(p1->data);
                    p1 = p1->next;
                }
                else {
                    merged.addAtEnd(p2->data);
                    p2 = p2->next;
                }
            }

            while (p1 != NULL) {
                merged.addAtEnd(p1->data);
                p1 = p1->next;
            }

            while (p2 != NULL) {
                merged.addAtEnd(p2->data);
                p2 = p2->next;
            }

            head = merged.head;
            tail = merged.tail;

            merged.head = NULL;
            merged.tail = NULL;

        }

       
};

int main() {
    LinkedList l1;
    l1.addAtEnd(34);
    l1.addAtEnd(1);
    l1.addAtEnd(67);
    l1.addAtEnd(12);
    l1.addAtEnd(59);
    cout << endl;

    cout << "Linked List 1:"<< endl;
    l1.displayInfo();
    cout << endl;

    LinkedList l2;
    l2.addAtEnd(23);
    l2.addAtEnd(45);
    l2.addAtEnd(78);
    cout << endl;

    cout << "Linked List 2:"<< endl;
    l2.displayInfo();
    cout << endl<<endl;

    cout << "Concatenated Linked List (without sorting):"<< endl;
    l1.concatenate(l2);
    l1.displayInfo();
    cout << endl<<endl;

    cout << "Sorted Linked List 1:"<< endl;
    l1.sort();
    l1.displayInfo();
    cout << endl<<endl;   

    cout << "Middle element of Linked List 1:"<< endl;
    l1.findMiddleElement();
    cout << endl;

    cout << "Sorted Linked List 2:"<< endl;
    l2.sort();
    l2.displayInfo();
    cout << endl<<endl;

    cout << "Merging both sorted linked lists:"<< endl;
    l1.mergeSorted(l2);
    l1.displayInfo();


    return 0;

}
