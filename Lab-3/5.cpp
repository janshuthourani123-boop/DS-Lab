#include <iostream>
using namespace std;

class SNode {
public:
    int data;
    SNode* next;
    SNode(int val) { data = val; next = nullptr; }
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) { data = val; next = nullptr; prev = nullptr; }
};

class SinglyList {
public:
    SNode* head;
    SinglyList() { head = nullptr; }

    void insertAtTail(int val) {
        SNode* newNode = new SNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        SNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        SNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    DNode* convertToDoubly() {
        if (!head) return nullptr;
        SNode* temp = head;
        DNode* dhead = new DNode(temp->data);
        DNode* dcurr = dhead;
        temp = temp->next;

        while (temp) {
            DNode* newNode = new DNode(temp->data);
            dcurr->next = newNode;
            newNode->prev = dcurr;
            dcurr = newNode;
            temp = temp->next;
        }
        return dhead;
    }

    SNode* convertToCircular() {
        if (!head) return nullptr;
        SNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = head;
        return head;
    }
};

void displayDoubly(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayCircular(SNode* head, int count) {
    SNode* temp = head;
    for (int i = 0; i < count; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    SinglyList sList;
    sList.insertAtTail(1);
    sList.insertAtTail(2);
    sList.insertAtTail(3);
    sList.insertAtTail(4);
    sList.insertAtTail(5);

    cout << "Original Singly Linked List: ";
    sList.display();

    DNode* dList = sList.convertToDoubly();
    cout << "Converted Doubly Linked List: ";
    displayDoubly(dList);

    SNode* cList = sList.convertToCircular();
    cout << "Converted Circular Linked List (showing 10 elements): ";
    displayCircular(cList, 10);

    return 0;
}
