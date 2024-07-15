#include <iostream>
/*
(a) (5 marks) Implement stack and queue from scratch using pointers in
C++. They should have all the functions supported by stacks and queues, e.g.,
insert, pop, top, etc. (Plagiarism will be strictly checked.)
*/
using namespace std;

// Node structure for both stack and queue
template <typename T>
struct Node {
    T data;
    Node* next;
};

// Stack class
template <typename T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    ~Stack() {
        while (!isEmpty())
            pop();
    }

    void push(T newData) {
        Node<T>* newNode = new Node<T>;
        newNode->data = newData;
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            exit(1);
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

// Queue class
template <typename T>
class Queue {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;

public:
    Queue() {
        frontNode = rearNode = nullptr;
    }

    ~Queue() {
        while (!isEmpty())
            dequeue();
    }

    void enqueue(T newData) {
        Node<T>* newNode = new Node<T>;
        newNode->data = newData;
        newNode->next = nullptr;
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        if (frontNode == nullptr)
            rearNode = nullptr;
    }

    T front() {
        if (isEmpty()) {
            cerr << "Queue is empty." << endl;
            exit(1);
        }
        return frontNode->data;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};

int main() {
    // Testing stack
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element of the stack: " << stack.top() << endl;
    stack.pop();
    cout << "Top element of the stack after popping: " << stack.top() << endl;

    // Testing queue
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element of the queue: " << queue.front() << endl;
    queue.dequeue();
    cout << "Front element of the queue after dequeue: " << queue.front() << endl;

    return 0;
}
