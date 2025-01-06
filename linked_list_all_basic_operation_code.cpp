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

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head; // New node points to the current head
    head = newNode;       // Update the head to the new node
}

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int value, int position) {
    if (position <= 0) {
        cout << "Position should be a positive integer.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    // If inserting at the beginning (position 1)
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the position where the node should be inserted
    Node* current = head;
    for (int i = 1; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }

    // If current is null, it means the position is out of bounds
    if (current == nullptr) {
        cout << "Position out of bounds.\n";
        delete newNode;
        return;
    }

    // Insert the node at the position
    newNode->next = current->next;
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

// Function to delete a node from the end of the linked list
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr) { // If there's only one node
        delete head;
        head = nullptr;
        return;
    }

    // Traverse to the second last node
    Node* current = head;
    while (current->next != nullptr && current->next->next != nullptr) {
        current = current->next;
    }

    // Delete the last node
    Node* temp = current->next;
    current->next = nullptr;
    delete temp;
}

// Function to delete a node from a specific position
void deleteFromPosition(Node*& head, int position) {
    if (position <= 0) {
        cout << "Position should be a positive integer.\n";
        return;
    }

    // If deleting the first node
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    // Traverse to the node just before the one we want to delete
    Node* current = head;
    for (int i = 1; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }

    // If current is null or the next node is null, position is out of bounds
    if (current == nullptr || current->next == nullptr) {
        cout << "Position out of bounds.\n";
        return;
    }

    // Delete the node at the specified position
    Node* temp = current->next;
    current->next = current->next->next;
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
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from specific position\n";
        cout << "7. Traverse\n";
        cout << "8. Search\n";
        cout << "9. Reverse\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 2:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(head, value, position);
                break;

            case 4:
                deleteFromBeginning(head);
                break;

            case 5:
                deleteFromEnd(head);
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteFromPosition(head, position);
                break;

            case 7:
                traverse(head);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(head, value))
                    cout << "Value found in the list.\n";
                else
                    cout << "Value not found in the list.\n";
                break;

            case 9:
                reverse(head);
                cout << "List reversed.\n";
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);

    return 0;
}

