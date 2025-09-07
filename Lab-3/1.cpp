#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value=0){
        data = value;
        next = nullptr;
    }
};
class SinglyList{
    Node* head;
    Node* tail;
    public:
    SinglyList(){
        head = NULL;
        tail = NULL;
    }
   
    void InsertAtTail(int value){
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Inserted at tail"<<endl;
    }
    Node* reverse(Node* value){
        Node* pre = nullptr;
        Node* curr = value;
        while (curr)
        {
           Node* Next = curr->next;
           curr->next = pre;
           pre = curr;
           curr = Next; 
        }
        return pre;
    }
    bool Palindrome(){
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* firstHalf = head;
        Node* secondHalf = reverse(slow);
        bool isPal = true;
        Node* temp = secondHalf;
        while (temp)
        {
            if (temp->data!=firstHalf->data)
            {
               isPal = false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        return isPal;
    }
    void Display(){
        Node* temp = head;
        while (temp)
        {
            cout << temp->data<< " ->";
            temp = temp->next;
        }
        cout << " NULL"<<endl;
    }
};
int main() {
    SinglyList s;
    int arr[7] = {3,1,2,5,2,1,3};
    for(int value:arr){
        s.InsertAtTail(value);
    }
    s.Display();
    if (s.Palindrome())
    {
        cout<<"palindrome"<<endl;
    }
    else
    {
        cout<<"not palindrome"<<endl;
    }
    
    return 0;
}
