#include <iostream>
#define MAX 10
using namespace std;

class Stack {
    int top;
    int a[MAX];
public:
    Stack() {
        top = -1;
    }

    void Push(int value) {
        if (top == MAX - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        a[++top] = value;
    }

    int Pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return a[top--];
    }

    int Top() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return a[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void Display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int arr[] = {3, 1, 2, 5, 8, 96, 6, 63};
    for (int value : arr) {
        s.Push(value);
    }

    s.Display();

    cout << "Top element: " << s.Top() << endl;

    cout << "Popping all elements: ";
    while (!s.isEmpty()) {
        cout << s.Pop() << " ";
    }
    cout << endl;

    s.Display();
    return 0;
}
