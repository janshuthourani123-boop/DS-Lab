#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = nullptr; }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void flatten(Node* head) {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* childList = curr->child;
                Node* childTail = childList;
                while (childTail->next) childTail = childTail->next;
                childTail->next = curr->next;
                curr->next = childList;
                curr->child = nullptr;
            }
            curr = curr->next;
        }
    }

    void display(Node* head) {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.head = new Node(1);
    list.head->next = new Node(2);
    list.head->next->next = new Node(3);

    list.head->next->child = new Node(4);
    list.head->next->child->next = new Node(5);

    cout << "Original list with child pointers (1→2→3, 2 has child 4→5)" << endl;

    list.flatten(list.head);

    cout << "Flattened list: ";
    list.display(list.head);

    return 0;
}
