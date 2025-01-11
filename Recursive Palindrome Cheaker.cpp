#include <iostream>
#include <cstring>
using namespace std;

// Recursive function to check if the string is a palindrome
void FindPalindrome(char arr[], int start, int end) {
    // Base case: if start index is greater than or equal to end, it's a palindrome
    if (start >= end) {
        cout << "The entered sequence is a palindrome." << endl;
        return;
    }
    
    // If characters at start and end don't match, it's not a palindrome
    if (arr[start] != arr[end]) {
        cout << "The entered sequence is not a palindrome." << endl;
        return;
    }
    
    // Recursive call with next indices
    FindPalindrome(arr, start + 1, end - 1);
}

int main() {
    const int size = 100; // Maximum size of the character array
    char arr[size];
    
    cout << "Enter a string: ";
    cin >> arr; // Input string from user

    // Call the recursive function with initial indices (0 and length-1)
    FindPalindrome(arr, 0, strlen(arr) - 1);

    return 0;
}

