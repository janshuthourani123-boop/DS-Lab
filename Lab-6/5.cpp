#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char val) { if (top < MAX - 1) arr[++top] = val; }
    char pop() { return (top == -1) ? '\0' : arr[top--]; }
    char peek() { return (top == -1) ? '\0' : arr[top]; }
    bool isEmpty() { return top == -1; }
};

class IntStack {
    int arr[MAX];
    int top;
public:
    IntStack() { top = -1; }
    void push(int val) { if (top < MAX - 1) arr[++top] = val; }
    int pop() { return (top == -1) ? 0 : arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty()) s.pop();
        } else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) postfix += s.pop();
    return postfix;
}

int evaluatePostfix(string postfix) {
    IntStack s;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int b = s.pop();
            int a = s.pop();
            int result = 0;
            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;
            s.push(result);
        }
    }
    return s.pop();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
