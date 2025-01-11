#include <iostream>
using namespace std;

// Recursive function to check if a number is prime
int isPrime(int num, int divisor) {
    if (divisor == num) {
        return 1; // If divisor equals num, it's prime
    }
    if (num % divisor == 0) {
        return 0; // If divisible by any number, it's not prime
    }
    return isPrime(num, divisor + 1); // Check the next divisor
}

int main() {
    int number;
    cout << "Enter a number to check if it is prime: ";
    cin >> number;

    if (number <= 1) {
        cout << number << " is not a prime number." << endl;
    } else {
        if (isPrime(number, 2) == 1) {
            cout << number << " is a prime number." << endl;
        } else {
            cout << number << " is not a prime number." << endl;
        }
    }

    return 0;
}

