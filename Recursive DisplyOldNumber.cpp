#include <iostream>
using namespace std;

// Recursive function to display odd numbers in a given range
void displayOddNumbers(int start, int end) {
    if (start > end) {
        return; // Base case: If start exceeds end, stop recursion
    }
    
    if (start % 2 != 0) { // Check if the number is odd
        cout << start << " ";
    }
    
    // Recursive call with the next number
    displayOddNumbers(start + 1, end);
}

int main() {
    int start, end;
    
    cout << "Enter the starting number: ";
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;

    cout << "Odd numbers between " << start << " and " << end << " are: ";
    displayOddNumbers(start, end);

    return 0;
}

