#include <iostream>
using namespace std;

int sumOfNumbers(int n) {
    if (n <= 0) {
        return 0;  // Base case: stop recursion when n reaches 0 or negative
    }

    return n + sumOfNumbers(n - 1);  // Recursive call to add current number with sum of previous numbers
}

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    int sum = sumOfNumbers(n);

    cout << "Sum of the first " << n << " numbers: " << sum << endl;

    return 0;
}