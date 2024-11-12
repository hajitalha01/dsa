#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* curr = new Node; // Create new node
    curr->data = value;
    curr->next = nullptr;
    return curr;
}

// Helper function to get the last node of the list
Node* lastNode(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* last = head;
    while (last->next != nullptr) {  // Traverse to the end
        last = last->next;
    }
    return last;
}

// Function to insert a node at the head of the list
void insertAtHead(Node*& head, int value) {
    Node* curr = createNode(value);  // Create new node
    curr->next = head;               // Point new node to current head
    head = curr;                     // Update head to new node
}

// Function to insert a node at the tail of the list
void insertAtTail(Node*& head, int value) {
    Node* curr = createNode(value);  // Create new node
    if (head == nullptr) {           // If list is empty, set as head
        head = curr;
    } else {
        Node* last = lastNode(head); // Get the last node
        last->next = curr;           // Link last node to new node
    }
}
void deletebyhead(Node*& head){
	if(head==nullptr){
		cout<<"the list is empty :\n";
	}
else{
    node* temp =head;
	head=head->next;
	delete temp;
	cout<<"delete : "<< temp->data;
	}
}
void deletebytail(N0de*& head){
		if(head==nullptr){
		cout<<"the list is empty :\n";
	}
	if(head->next==nullptr){
		delete head;
		head = nullptr;
	}
else{
	node* last= lastNode(head);
	while(last->next->next!=nullptr){
		last=last->next;
	}
	delete last->next;
	last->next =nullptr;	
}}
void deletebyrollno(Node*& head, int rollno) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    // Case 1: If the head node has the roll number
    if (head->data == rollno) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node with roll number " << rollno << endl;
        return;
    }

    // Case 2: Traverse to find the node with the roll number
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != rollno) {
        temp = temp->next;
    }

    // If we reached the end without finding the roll number
    if (temp->next == nullptr) {
        cout << "Roll number " << rollno << " not found.\n";
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        cout << "Deleted node with roll number " << rollno << endl;
    }
}


// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Create a new node\n";
        cout << "2. Insert at head\n";
        cout << "3. Insert at tail\n";
        cout << "4 delete BY HEAD\n";
        cout << "5 delete at tail\n";
        cout <<  "6 delete by rollno \n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value for new node: ";
                cin >> value;
                createNode(value);  // Just creates a new node, not adding it to list
                cout << "Node with value " << value << " created.\n";
                break;
            case 2:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(head, value);
                cout << "Inserted " << value << " at head.\n";
                break;
            case 3:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                insertAtTail(head, value);
                cout << "Inserted " << value << " at tail.\n";
                break;
            case 4:
            	cout<<"delete by head :"<<endl;
            	deletebyhead(head);
            case 5:
            	cout<<"delete by tail :\n";
            	deletebytail(head);
            case 6:
            	cout<<"delete by rollno :";
            	deletebyrollno(head);
            case 7:
                cout << "Linked List: ";
                displayList(head);
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 9);

    return 0;
}
void createNodeBeforeRollno(Node*& head, int rollno, int value) {
    Node* newNode = createNode(value);  // Naya node banaya

    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // Head ko check karte hain
    if (head->data == rollno) {  // Agar rollno head mein hai
        newNode->next = head;    // New node ko head ke pehle daala
        head = newNode;
        cout << "Node with value " << value << " inserted before " << rollno << endl;
        return;
    }

    // Traverse karna shuru
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != rollno) {
        temp = temp->next;
    }

    // Roll number nahi mila
    if (temp->next == nullptr) {
        cout << "Roll number " << rollno << " not found.\n";
    } else {
        // Rollno mila, toh new node insert karo
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node with value " << value << " inserted before " << rollno << endl;
    }
}
void createNodeAfterRollno(Node*& head, int rollno, int value) {
    Node* temp = head;

    // Roll number ko find karne ke liye traverse karo
    while (temp != nullptr && temp->data != rollno) {
        temp = temp->next;
    }

    // Agar roll number nahi mila
    if (temp == nullptr) {
        cout << "Roll number " << rollno << " not found.\n";
    } else {
        // Roll number mila, toh naye node ko insert karo
        Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node with value " << value << " inserted after " << rollno << endl;
    }
}


