#include <iostream>
#include <string>
using namespace std;

struct Process {
    int id;
    int priority;
};

class Queue {
    int front, rear, size;
    Process* arr;
public:
    Queue(int s) {
        front = rear = -1;
        size = s;
        arr = new Process[size];
    }
    ~Queue() { delete[] arr; }

    bool isFull() { return rear == size - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = p;
        cout << "Process " << p.id << " (priority " << p.priority << ") arrived.\n";
    }

    Process dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return {-1, -1};
        }
        return arr[front++];
    }
};

class Stack {
    int top, size;
    Process* arr;
public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new Process[size];
    }
    ~Stack() { delete[] arr; }

    bool isFull() { return top == size - 1; }
    bool isEmpty() { return top == -1; }

    void push(Process p) {
        if (isFull()) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = p;
        cout << "Process " << p.id << " moved to stack for execution.\n";
    }

    Process pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return {-1, -1};
        }
        return arr[top--];
    }
};

int main() {
    Queue arrivalQueue(5);
    Stack execStack(5);

    arrivalQueue.enqueue({101, 1});
    arrivalQueue.enqueue({102, 3});
    arrivalQueue.enqueue({103, 2});
    arrivalQueue.enqueue({104, 4});

    cout << "\n--- Scheduling Started ---\n";

    while (!arrivalQueue.isEmpty()) {
        Process p = arrivalQueue.dequeue();

        if (p.priority >= 3) {
            execStack.push(p);
        } else {
            cout << "Process " << p.id << " executed directly (low priority).\n";
        }
    }

    cout << "\n--- Executing High Priority Processes ---\n";
    while (!execStack.isEmpty()) {
        Process p = execStack.pop();
        cout << "Executing Process " << p.id << " (priority " << p.priority << ")\n";
    }

    cout << "\n--- All Processes Completed ---\n";
    return 0;
}
