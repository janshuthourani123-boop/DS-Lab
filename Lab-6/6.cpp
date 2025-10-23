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

bool isRightAssociative(char op) {
    return op == '^';
}

string reverseString(string s) {
    string rev = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '(') rev += ')';
        else if (s[i] == ')') rev += '(';
        else rev += s[i];
    }
    return rev;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            if (!s.isEmpty()) s.pop();
        } else if (isOperator(c)) {
            while (!s.isEmpty() && 
                   ((precedence(s.peek()) > precedence(c)) || 
                   (precedence(s.peek()) == precedence(c) && !isRightAssociative(c))) && 
                   s.peek() != '(') {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) postfix += s.pop();
    return postfix;
}

string infixToPrefix(string infix) {
    string rev = reverseString(infix);
    string postfix = infixToPostfix(rev);
    string prefix = "";
    for (int i = postfix.length() - 1; i >= 0; i--) prefix += postfix[i];
    return prefix;
}

int evaluatePrefix(string prefix) {
    IntStack s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int a = s.pop();
            int b = s.pop();
            int result = 0;
            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;
            else if (c == '^') {
                result = 1;
                for (int j = 0; j < b; j++) result *= a;
            }
            s.push(result);
        }
    }
    return s.pop();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Result: " << evaluatePrefix(prefix) << endl;
    return 0;
}
