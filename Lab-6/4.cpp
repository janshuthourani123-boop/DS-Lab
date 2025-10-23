#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
    int front, rear;
    int arr[MAX];
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
    }

    bool isEmpty() {
        return front == -1;
    }

    void Enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = value;
        cout << value << " enqueued." << endl;
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void Display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();
    q.Dequeue();
    q.Dequeue();
    q.Display();
    q.Enqueue(60);
    q.Enqueue(70);
    q.Display();
    return 0;
}
