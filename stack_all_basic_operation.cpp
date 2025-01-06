#include <iostream>
#include <stack> // Include stack header
using namespace std;

int main() {
    stack<int> s; // Declare a stack of integers
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top)\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Size of Stack\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value); // Push an element
                cout << value << " pushed into stack.\n";
                break;

            case 2:
                if (s.empty()) {
                    cout << "Stack is empty! Cannot pop.\n";
                } else {
                    cout << s.top() << " popped from stack.\n";
                    s.pop(); // Pop the top element
                }
                break;

            case 3:
                if (s.empty()) {
                    cout << "Stack is empty! No top element.\n";
                } else {
                    cout << "Top element is: " << s.top() << "\n"; // View the top element
                }
                break;

            case 4:
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;

            case 5:
                cout << "Size of stack: " << s.size() << "\n"; // Get the size of the stack
                break;

            case 6:
                if (s.empty()) {
                    cout << "Stack is empty! Nothing to display.\n";
                } else {
                    cout << "Stack elements: ";
                    stack<int> temp = s; // Use a temporary stack to display elements
                    while (!temp.empty()) {
                        cout << temp.top() << " "; // Display top element
                        temp.pop(); // Remove top element
                    }
                    cout << "\n";
                }
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

