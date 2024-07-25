#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtK(int k, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr && k == 1) {
            head = newNode;
            tail = newNode;
        } else if (k == 1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            int pos = 1;
            while (pos < k - 1 && temp->next != nullptr) {
                temp = temp->next;
                pos++;
            }
            if (pos == k - 1) {
                newNode->next = temp->next;
                if (temp->next != nullptr)
                    temp->next->prev = newNode;
                temp->next = newNode;
                newNode->prev = temp;
                if (newNode->next == nullptr)
                    tail = newNode;
            } else {
                cout << "Position out of range." << endl;
            }
        }
    }

    void insertAtSecondLast(int val) {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (tail->prev == nullptr) {
            newNode->next = tail;
            tail->prev = newNode;
            head = newNode;
        } else {
            Node* secondLast = tail->prev;
            newNode->next = tail;
            newNode->prev = secondLast;
            secondLast->next = newNode;
            tail->prev = newNode;
        }
    }

    int findMax() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return INT_MIN;
        }
        int maxVal = head->data;
        Node* temp = head->next;
        while (temp != nullptr) {
            if (temp->data > maxVal)
                maxVal = temp->data;
            temp = temp->next;
        }
        return maxVal;
    }

    void deleteOdd() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            if (current->data % 2 != 0) {
                if (current == head) {
                    head = head->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
            }
            current = nextNode;
        }
    }

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList li;
    li.insertAtK(1, 10);
    li.insertAtK(2, 20);
    li.insertAtK(3, 30);
    li.insertAtK(4, 40);
    li.insertAtK(5, 50);
    
    int choice;
    do {
        cout << "Choose an operation:" << endl;
        cout << "1. Insert at k-th position" << endl;
        cout << "2. Insert at second last position" << endl;
        cout << "3. Find the maximum" << endl;
        cout << "4. Delete all odd elements" << endl;
        cout << "5. Count occurrences of a specific element" << endl;
        cout << "6. Display the list" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int k, val;
                cout << "Enter position and value to insert: ";
                cin >> k >> val;
                li.insertAtK(k, val);
                break;
            }
            case 2: {
                int val;
                cout << "Enter value to insert at second last position: ";
                cin >> val;
                li.insertAtSecondLast(val);
                break;
            }
            case 3: {
                cout << "Maximum value in the list: " << li.findMax() << endl;
                break;
            }
            case 4: {
                li.deleteOdd();
                cout << "Odd elements deleted.Print the list to see the change" << endl;
                break;
            }
            case 5: {
                int key;
                cout << "Enter element to count occurrences: ";
                cin >> key;
                cout << "Occurrences of " << key << " in the list: " << li.countOccurrences(key) << endl;
                break;
            }
            case 6: {
                cout << "Current list: ";
                li.display();
                break;
            }
            case 7: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
