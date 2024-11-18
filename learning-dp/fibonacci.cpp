#include<iostream>
using namespace std;

// Memoization - 
// Overlapping Subproblems

int count = 0; //This will indicate how many times the function has been called.
int dp[40]; //Some random array of length which will store the value of n we already calculated.
int helper(int n) {
    count++;
    if(n == 1 || n == 2) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    // Memoize and return the result
    return dp[n] = helper(n - 1) + helper(n - 2);
}

void solve() {
    int n;
    cin >> n;

    // Initialize the memoization array with -1
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    // Call the helper function and display results
    int result = helper(n);
    cout << "Result: " << result << endl;
    cout << "Function calls: " << count << endl;
}

int main() {
    solve();
    return 0;
}
