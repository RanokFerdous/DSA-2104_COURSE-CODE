#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* next;
};

// Class for Stack implementation
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Destructor to clean up the memory
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << "\n";
        delete temp;
    }

    // Function to peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek.\n";
            return -1; // Return a sentinel value to indicate an empty stack
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

// Main function for testing the stack implementation
int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                cout << "Top element: " << stack.peek() << "\n";
                break;

            case 4:
                stack.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
