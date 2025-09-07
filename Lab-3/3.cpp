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
    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* ReverseInCount(Node* s,int k){
        Node* pre = nullptr; 
        Node* curr = s;
        int count = 0;
        while (curr && count<k)
        {
         Node* Next = curr->next;
         curr->next = pre;
         pre = curr;
         curr = Next;
         count++;
        }
         if (s) {
        s->next = curr;
    }
        return pre;
    }
    void reverse(int k){
        head = ReverseInCount(head,k);
    }
     void Display(){
        Node* temp = head;
        while (temp!=nullptr)
        {
            cout <<temp->data << " ->";
            temp = temp->next;
        }
        cout << " NULL"<<endl;
    }
};
int main() {
    SinglyList s, s1;
    int arr1[7] = {1, 2, 3, 5, 7, 9, 11};
    for (int value : arr1) s.InsertAtTail(value);
    s.Display();

    s.reverse(3);
    s.Display();

    return 0;
}
