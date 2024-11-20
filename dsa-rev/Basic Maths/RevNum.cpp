#include<bits/stdc++.h>
using namespace std;

int revNum(int n) {
    int rev = 0;
    while(n > 0) {
        int lastDigit = n % 10;
        n = n / 10;
        rev = (rev * 10) +  lastDigit;
    }
    return rev;
}

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << "The reversed number is : " << revNum(n) << endl;
}