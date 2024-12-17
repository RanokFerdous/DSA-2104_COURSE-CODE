#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* nextlink;
};


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->nextlink;
    }
    cout << "NULL" << endl;
}


Node* insertAtEnd(Node* head, int value) {
    Node* newnode = new Node;
    newnode->data = value;
    newnode->nextlink = NULL;

    if (head == NULL) {

        return newnode;
    }

    Node* temp = head;
    while (temp->nextlink != NULL) {
        temp = temp->nextlink;
    }
    temp->nextlink = newnode;

    return head;
}


Node* insertAtBeginning(Node* head, int value) {
    Node* newnode = new Node;
    newnode->data = value;
    newnode->nextlink = head;
    return newnode;
}


int getSize(Node* head) {
    int size = 0;
    Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->nextlink;
    }
    return size;
}

int main() {
    Node* head = NULL;

    head = insertAtEnd(head, 43);
    head = insertAtEnd(head, 123);
    head = insertAtEnd(head, 34);

    display(head);

    // Insert at the end  (4 and 3)
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 3);

     display(head);
    // Insert at the beginning (value 23)
    head = insertAtBeginning(head, 23);


    display(head);


    cout << "Size of the linked list: " << getSize(head) << endl;

    return 0;
}

