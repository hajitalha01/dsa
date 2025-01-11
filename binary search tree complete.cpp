#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Find the minimum value node in the subtree
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root; // Node not found
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value); // Go to the left subtree
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value); // Go to the right subtree
    } else {
        // Node found
        if (root->left == nullptr && root->right == nullptr) {
            // Case 1: No children (leaf node)
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            // Case 2: One child (right child)
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            // Case 2: One child (left child)
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // Case 3: Two children
            Node* temp = findMin(root->right); // Find in-order successor
            root->data = temp->data;          // Replace root's value with successor's value
            root->right = deleteNode(root->right, temp->data); // Delete successor
        }
    }
    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    int n, value, choice;

    cout << "Enter the number of elements to insert in the BST: ";
    cin >> n;

    cout << "Enter the values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    do {
        // Menu display
        cout << "\nChoose an option:\n";
        cout << "1. In-order Traversal\n";
        cout << "2. Pre-order Traversal\n";
        cout << "3. Post-order Traversal\n";
        cout << "4. Delete a value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "In-order Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 2:
                cout << "Pre-order Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "Post-order Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Value deleted (if it existed).\n";
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

