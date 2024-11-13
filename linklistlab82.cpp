#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    string address;
    int itemCount;
    float paymentAmount;
    Order* next;
};

class OrderQueue {
private:
    Order* front;
    Order* rear;
    int nextOrderID;

public:
    OrderQueue() : front(NULL), rear(NULL), nextOrderID(1) {}

    void addOrder(string customerName, string address, int itemCount, float paymentAmount) {
        Order* newOrder = new Order;
        newOrder->orderID = nextOrderID++;
        newOrder->customerName = customerName;
        newOrder->address = address;
        newOrder->itemCount = itemCount;
        newOrder->paymentAmount = paymentAmount;
        newOrder->next = NULL;

        if (rear == NULL) {
            front = rear = newOrder;
        } else {
            rear->next = newOrder;
            rear = newOrder;
        }
        cout << "Order ID " << newOrder->orderID << " added to the queue.\n";
    }

    void processOrder() {
        if (front == NULL) {
            cout << "No orders to process.\n";
            return;
        }

        Order* temp = front;
        cout << "Processing Order ID " << temp->orderID << ":\n";
        cout << "Customer Name: " << temp->customerName << "\n";
        cout << "Address: " << temp->address << "\n";
        cout << "Items: " << temp->itemCount << "\n";
        cout << "Payment Amount: $" << temp->paymentAmount << "\n";
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        cout << "Order processed.\n";
    }

    void displayOrders() {
        if (front == NULL) {
            cout << "No orders in the queue.\n";
            return;
        }
        Order* current = front;
        cout << "Orders in Queue:\n";
        while (current != NULL) {
            cout << "Order ID: " << current->orderID << "\n";
            cout << "Customer Name: " << current->customerName << "\n";
            cout << "Address: " << current->address << "\n";
            cout << "Items: " << current->itemCount << "\n";
            cout << "Payment Amount: $" << current->paymentAmount << "\n\n";
            current = current->next;
        }
    }
};

int main() {
    OrderQueue orderQueue;
    int choice;
    string customerName, address;
    int itemCount;
    float paymentAmount;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Add an order\n";
        cout << "2. Process an order\n";
        cout << "3. Display all orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, customerName);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter number of items: ";
                cin >> itemCount;
                cout << "Enter payment amount: ";
                cin >> paymentAmount;
                orderQueue.addOrder(customerName, address, itemCount, paymentAmount);
                break;
            case 2:
                orderQueue.processOrder();
                break;
            case 3:
                orderQueue.displayOrders();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
