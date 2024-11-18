#include<iostream>
using namespace std;

struct stack {
    int* arr;   
    int top;    
    int maxsize; 
};
void initialize(stack &s, int size) {
    s.arr = new int[size];  
    s.top = -1;           
    s.maxsize = size;    
}
void push(stack &s, int value) {
    if (s.top == s.maxsize - 1) {
        cout << "Stack is full" << endl; 
    } else {
        s.top++;        
        s.arr[s.top] = value; 
        cout << "Pushed " << value << " into the stack." << endl;
    }
}
int pop(stack &s) {
    if (s.top == -1) {
        cout << "Stack is empty." << endl;  
        return -1;
    } else {
        int poppedValue = s.arr[s.top];  
        s.top--;                         
        cout << "Popped value is: " << poppedValue << endl;
        return poppedValue;
    }
}

int main() {
    stack s;
    int size;
    cout << "Enter the size of stack: ";
    cin >> size;
    initialize(s, size);
    push(s, 12);
    push(s, 24);
    push(s, 36);
    pop(s);
    pop(s);

    return 0;
}
