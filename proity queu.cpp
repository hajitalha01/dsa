#include <iostream>
using namespace std;

struct queue {
    int* arr;
    int* proity;
    int front;
    int rear;
    int size;
};

void initialize(struct queue& q, int s) {
    q.arr = new int[s];
    q.proity = new int[s];
    q.front = -1;
    q.rear = -1;
    q.size = s;
}

void enqueue(struct queue& q, int val, int p) {
    if (q.rear == q.size - 1) {
        cout << "Queue is full." << endl;
    } else {
        if (q.front == -1)
            q.front = 0;
        int i;
        for (i = q.rear; i >= q.front; i--) {
            if (p > q.proity[i]) {
                q.arr[i + 1] = q.arr[i];
                q.proity[i + 1] = q.proity[i];
            } else
                break;
        }
        q.arr[i + 1] = val;
        q.proity[i + 1] = p;
        q.rear++;
    }
}

void dequeue(struct queue& q) {
    if (q.front == -1 || q.front > q.rear) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Dequeued value is: " << q.arr[q.front]
             << " with priority: " << q.proity[q.front] << endl;
        q.front++;
    }
}

void display(struct queue& q) {
    if (q.front == -1 || q.front > q.rear) {
        cout << "Queue is empty." << endl;
    } else {
        for (int i = q.front; i <= q.rear; i++) {
            cout << "Value: " << q.arr[i] << " (Priority: " << q.proity[i] << ")" << endl;
        }
    }
}

int main() {
    struct queue q;
    int s, choice, val, p;

    cout << "Enter the size of the queue: ";
    cin >> s;
    initialize(q, s);

    do {
        cout << "\nPress 1 to enqueue." << endl;
        cout << "Press 2 to dequeue." << endl;
        cout << "Press 3 to display." << endl;
        cout << "Press 4 to exit." << endl;
        cout << "Select one: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value and priority to enqueue: ";
                cin >> val >> p;
                enqueue(q, val, p);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                cout << "All the values are here:" << endl;
                display(q);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 4);

    delete[] q.arr;    // Free allocated memory
    delete[] q.proity; // Free allocated memory
    return 0;
}
