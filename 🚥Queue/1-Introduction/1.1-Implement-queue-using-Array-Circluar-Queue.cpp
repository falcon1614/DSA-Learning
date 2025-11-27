// Implement queue using Array (Circluar Queue)

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front, rear;
    int size;

public:
    // Constructor
    Queue(int n) {
        arr = new int[n];
        front = rear = -1;
        size = n;
    }

    // Empty
    bool Isempty() {
        return (front == -1);
    }

    // Full
    bool Isfull() {
        return ((rear + 1) % size == front);
    }

    // Push
    void push(int x) {
        if (Isfull()) {
            cout << "Queue is full" << endl;
            return;
        }

        if (Isempty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
    }

    // Pop
    void pop() {
        if (Isempty()) {
            cout << "Queue underflow" << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % size;
        }
    }

    // Front element
    int start() {
        if (Isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.start() << endl;

    q.pop();
    cout << "Front element after pop: " << q.start() << endl;

    q.pop();
    q.pop();

    cout << "Queue empty? " << (q.Isempty() ? "Yes" : "No") << endl;

    return 0;
}
