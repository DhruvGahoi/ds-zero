#include<bits/stdc++.h>
using namespace std;

int count(int n) {
    // int cnt = 0;
    // while(n > 0) {
    //     cnt++;
    //     int lastDigit = n % 10;
    //     n = n / 10; 
    // }
    // return cnt;

    //----------------------------
    int cnt = (int)(log10(n) + 1);
    return cnt;
}

int main() {
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    cout << "The number of digits are : " << count(n) << endl;

}