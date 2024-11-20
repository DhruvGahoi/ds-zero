#include<bits/stdc++.h>
using namespace std;

bool isValid(int n) {
    int dup = n;
    int sum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        sum = (lastDigit * lastDigit * lastDigit) + sum;
        n = n / 10;
    }
    if(sum == dup)  {
        return true;
    } else {
        return false;
    }
}


int main() {
    int n;
    cout << "Enter the number : " ;
    cin >> n;
    if(isValid(n)){
        cout << "The given number is a armstrong number." << endl;
    } else {
        cout << "The number is not a armstrong number." << endl;
    }

    return 0;
}