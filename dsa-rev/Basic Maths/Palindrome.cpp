#include<iostream>
using namespace std;

bool isPalindrome(int n) {
    int check = n;
    int rev = 0;
    while(n > 0) {
        int lastDigit = n % 10;
        n = n / 10;
        rev = (rev * 10) + lastDigit;
    }
    if(check == rev) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    if(isPalindrome(n)){
        cout << "The given number is a palindrome." << endl;
    } else {
        cout << "The number is not a palindrome" << endl;
    }
    return 0;
}