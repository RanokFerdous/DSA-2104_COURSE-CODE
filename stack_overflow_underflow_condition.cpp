#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;  //  just return from the function not from the all code.
        }
        arr[++top] = x;
    }

    // Function to remove an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Function to return the top element of the stack
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        cout << "Stack is empty\n";
        return -1;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;   // ( top==-1 . if this will be true then return 1  otherwise ans: 0 retrun false.)
    }

    // Function to check if the stack is full
    bool isFull() {  // trure false condition.  return 1 or 0.
        return top == capacity - 1;  //if top== 4 then ture and return 1.        last index . if size=5 then top==4 will be.
    }

    // Function to display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack s(size);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.push(40);
    s.push(50);
    s.push(60); // Will show overflow if size < 5

    s.display();

    while (!s.isEmpty()) {
        cout << "Popped: " << s.pop() << endl;
    }

    s.pop(); // Will show underflow

    return 0;
}

