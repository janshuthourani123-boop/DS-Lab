#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void Push(string value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << value << endl;
    }

    void Pop() {
        if (top == nullptr) {
            cout << "No previous page (stack underflow)." << endl;
            return;
        }
        Node* temp = top;
        cout << "Going back from: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    string Peek() {
        if (top == nullptr) {
            cout << "No current page (stack empty)." << endl;
            return "";
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void Display() {
        if (isEmpty()) {
            cout << "No pages in history." << endl;
            return;
        }
        cout << "\nBrowser History (most recent first):\n";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack history;
    history.Push("www.google.com");
    history.Push("www.youtube.com");
    history.Push("www.github.com");
    history.Push("www.stackoverflow.com");

    history.Display();

    cout << "\nCurrent Page: " << history.Peek() << endl;

    history.Pop();
    cout << "Now on: " << history.Peek() << endl;

    history.Pop();
    cout << "Now on: " << history.Peek() << endl;

    history.Display();

    return 0;
}
