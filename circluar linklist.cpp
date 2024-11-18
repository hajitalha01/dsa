#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert a node at the head of the circular linked list
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node;  
    newNode->data = value;

    if (head == nullptr) {  
        head = newNode;
        newNode->next = head;  
    } else {
        Node* temp = head;

        // Find last node
        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;  
        temp->next = newNode;  
        head = newNode;        
    }
}

// Insert a node at the tail of the circular linked list
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node;  
    newNode->data = value;

    if (head == nullptr) {  
        head = newNode;
        newNode->next = head;  
    } else {
        Node* temp = head;

        // Find last node
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;  
        newNode->next = head;  
    }
}

// Delete a node from the head of the circular linked list
void deleteByHead(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (head->next == head) {  // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;

        // Find last node
        while (temp->next != head) {
            temp = temp->next;
        }

        Node* toDelete = head;
        head = head->next;
        temp->next = head;

        delete toDelete;
    }

    cout << "Node deleted from the head.\n";
}

// Delete a node from the tail of the circular linked list
void deleteByTail(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (head->next == head) {  // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;

        // Find second last node
        while (temp->next->next != head) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = head;

        delete toDelete;
    }

    cout << "Node deleted from the tail.\n";
}

// Display the circular linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD)\n";  // Circular list loop indication
}

// Main Function
int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at tail\n";
        cout << "3. Delete by head\n";
        cout << "4. Delete by tail\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(head, value);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                insertAtTail(head, value);
                break;
            case 3:
                deleteByHead(head);
                break;
            case 4:
                deleteByTail(head);
                break;
            case 5:
                cout << "Circular Linked List: ";
                displayList(head);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
