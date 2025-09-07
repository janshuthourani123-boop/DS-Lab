#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value = 0) {
        data = value;
        next = nullptr;
    }
};

class SinglyList {
    Node* head;
    Node* tail;
public:
    SinglyList() {
        head = tail = nullptr;
    }
    void InsertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* getHead() { return head; }
    void merge(Node* l2) {
        Node* l1 = head;
        if (!l1) { head = l2; return; }
        if (!l2) return;
        Node* mergedHead = nullptr;
        Node* mergedTail = nullptr;
        if (l1->data <= l2->data) {
            mergedHead = l1;
            l1 = l1->next;
        } else {
            mergedHead = l2;
            l2 = l2->next;
        }
        mergedTail = mergedHead;
        while (l1 && l2) {
            if (l1->data <= l2->data) {
                mergedTail->next = l1;
                l1 = l1->next;
            } else {
                mergedTail->next = l2;
                l2 = l2->next;
            }
            mergedTail = mergedTail->next;
        }
        if (l1) mergedTail->next = l1;
        if (l2) mergedTail->next = l2;
        head = mergedHead;
    }
    void Display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyList s, s1;
    int arr1[7] = {1, 2, 3, 5, 7, 9, 11};
    for (int value : arr1) s.InsertAtTail(value);
    s.Display();
    int arr2[5] = {2, 4, 6, 8, 10};
    for (int value : arr2) s1.InsertAtTail(value);
    s1.Display();
    s.merge(s1.getHead());
    s.Display();
    return 0;
}
