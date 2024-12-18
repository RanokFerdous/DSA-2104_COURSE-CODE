#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to traverse and print the linked list
void traverse(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) { // If the list is empty
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to search for a value in the linked list
bool search(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) return true;
        current = current->next;
    }
    return false;
}

// Function to reverse the linked list
void reverse(Node*& head) {
    Node *prev = nullptr, *current = head, *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    Node* head = nullptr; // Initialize the head of the linked list as null
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Delete from beginning\n";
        cout << "3. Traverse\n";
        cout << "4. Search\n";
        cout << "5. Reverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 2:
                deleteFromBeginning(head);
                break;

            case 3:
                traverse(head);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(head, value))
                    cout << "Value found in the list.\n";
                else
                    cout << "Value not found in the list.\n";
                break;

            case 5:
                reverse(head);
                cout << "List reversed.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

