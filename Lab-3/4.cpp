#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() { head = nullptr; }
    void createList(int N) {
        Node* prev = nullptr;
        for (int i = 1; i <= N; i++) {
            Node* newNode = new Node(i);
            if (head == nullptr) head = newNode;
            else prev->next = newNode;
            prev = newNode;
        }
        prev->next = head;
    }
    int getJosephusPosition(int k) {
        Node* ptr = head;
        Node* prev = nullptr;
        while (ptr->next != ptr) {
            for (int count = 1; count < k; count++) {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = ptr->next;
            Node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        return ptr->data;
    }
};

int josephus(int n, int k) {
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }
    return result + 1;
}

int main() {
    int N = 7, k = 3;

    CircularLinkedList cll;
    cll.createList(N);
    cout << "Survivor (Linked List): " << cll.getJosephusPosition(k) << endl;

    cout << "Survivor (Efficient): " << josephus(N, k) << endl;

    return 0;
}
