#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = NULL;
    }
    void initializeList(int values[], int size) {
        head = new Node(values[0]);
        Node* current = head;
        for (int i = 1; i < size; ++i) {
            current->next = new Node(values[i]);
            current = current->next;
        }
    }

    void insertIntoMid(int value) {
        if (head == NULL) {
            head = new Node(value);
            return;
        }
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* newNode = new Node(value);
        newNode->next = slow->next;
        slow->next = newNode;
    }

    void addArrayToEnd(int arr[], int size) {
        Node* current = head;
        
        while (current->next != NULL) {
            current = current->next;
        }
        
        for (int i = 0; i < size; ++i) {
            current->next = new Node(arr[i]);
            current = current->next;
        }
    }
    
    void deleteKthElement(int k) {
        if (head == NULL || k <= 0) {
            return;
        }
        
        if (k == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* current = head;
        for (int i = 1; i < k - 1 && current != NULL; ++i) {
            current = current->next;
        }
        
        if (current == NULL || current->next == NULL) {
            return; 
        }
        
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    

    void replaceLastWithSum() {
        if (head == NULL) {
            return;
        }
        
        int sum = 0;
        Node* current = head;
        
        while (current->next != NULL) {
            sum += current->data;
            current = current->next;
        }
        
        current->data = sum;
    }

    vector<int> searchEvenNumbers() {
        vector<int> evenNumbers;
        Node* current = head;
        
        while (current != NULL) {
            if (current->data % 2 == 0) {
                evenNumbers.push_back(current->data);
            }
            current = current->next;
        }
        
        return evenNumbers;
    }
    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList Li;
    int choice;

    int initialValues[] = {10, 20, 30, 40, 50};
    Li.initializeList(initialValues, 5);
    
    do {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Insert into mid position" << endl;
        cout << "2. Add elements of an array at the end" << endl;
        cout << "3. Delete k-th element" << endl;
        cout << "4. Replace last element with sum" << endl;
        cout << "5. Search even numbers and display" << endl;
        cout << "6. Print the linked list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert into mid position: ";
                cin >> value;
                Li.insertIntoMid(value);
                break;
            }
            case 2: {
                int size;
                cout << "Enter the size of the array: ";
                cin >> size;
                
                int *arr = new int[size];
                cout << "Enter " << size << " elements of the array: ";
                for (int i = 0; i < size; ++i) {
                    cin >> arr[i];
                }
                
                Li.addArrayToEnd(arr, size);
                delete[] arr;
                break;
            }
            case 3: {
                int k;
                cout << "Enter the position of the element to delete: ";
                cin >> k;
                Li.deleteKthElement(k);
                break;
            }
            case 4: {
                Li.replaceLastWithSum();
                cout << "Last element replaced with the sum of the list." << endl;
                break;
            }
            case 5: {
                vector<int> evenNumbers = Li.searchEvenNumbers();
                cout << "Even Numbers in the LL: ";
                for (int num : evenNumbers) {
                    cout << num << " ";
                }
                cout << endl;
                break;
            }
            case 6: {
                cout << "Linked List: ";
                Li.print();
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


