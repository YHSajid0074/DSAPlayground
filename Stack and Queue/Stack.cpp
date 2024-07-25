#include <iostream>

using namespace std;

class Stack {
private:
    class Node {
    public:
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cerr << "Stack underflow! Unable to pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() const {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            // Returning a default value
            return -1; // Or any other default value suitable for your use case
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Stack elements: ";
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
}

