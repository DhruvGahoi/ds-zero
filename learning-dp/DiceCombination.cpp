//Question --> Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
// For example, if n=3, there are 4 ways:

// 1+1+1
// 1+2
// 2+1
// 3

// <-----------------------------------------Solution-------------------------------------------------->
#include <iostream>
using namespace std;

int dp[1000];

int func(int n) {
    if(n < 0) return 0; // No way we can get sum 0

    if(n == 0) return 1; // Only 1 way where we can get sum 0

    if (dp[n] != -1) return dp[n]; // Return already computed result

    dp[n] = 0; // Initiating everything with 0

    for(int i = 0; i <= 6; i++) {
        dp[n] += func(n - i);      // Add ways to form (n - i)
    }

    return dp[n];
}

void solve() {
    int n;
    cin >> n;

    // Initialize DP table with -1
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    cout << func(n) << endl;
}

int main() {
    solve();
    return 0;
}