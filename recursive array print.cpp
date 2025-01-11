#include <iostream>
using namespace std;

// Recursive function to print array elements
void printArrayRecursively(int arr[], int size, int index) {
    if (index >= size) { // Base case: If index is out of bounds, stop recursion
        return;
    }
    cout << arr[index] << " "; // Print the current element
    printArrayRecursively(arr, size, index + 1); // Recursive call for the next index
}

int main() {
    // Create a static array of size 10
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Array elements are: ";
    // Call the recursive function starting from index 0
    printArrayRecursively(arr, 10, 0);

    return 0;
}

