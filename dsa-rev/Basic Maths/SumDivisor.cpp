#include <bits/stdc++.h>
using namespace std;

int sumOfDivisors(int number) {
    int sum = 0;

    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n; 

    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += sumOfDivisors(i);
    }

    cout << "The value of the summation is: " << result << endl;

    return 0;
}