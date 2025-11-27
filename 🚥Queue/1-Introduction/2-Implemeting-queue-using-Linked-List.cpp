
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node *front;
    Node *rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!Isempty()) {
            pop();
        }
    }

    bool Isempty() {
        return front == nullptr;
    }

    void push(int x) {
        if (Isempty()) {
            front = new Node(x);
            rear = front;
        } else {
            rear->next = new Node(x);
            rear = rear->next;
        }
    }

    void pop() {
        if (Isempty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) { // if queue becomes empty
            rear = nullptr;
        }
    }

    int start() {
        if (Isempty()) {
            cout << "Queue is empty, no front element." << endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.start() << endl;

    q.pop();
    cout << "Front element after pop: " << q.start() << endl;

    q.pop();
    q.pop();

    cout << "Queue empty? " << (q.Isempty() ? "Yes" : "No") << endl;

    q.pop(); // Test popping from empty queue

    q.push(40);
    cout << "Front element after pushing 40: " << q.start() << endl;

    return 0;
}

