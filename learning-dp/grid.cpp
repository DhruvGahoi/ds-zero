// There exists a grid where we can only move down or right. We have to calculate the minimum path from [0, 0] to [n-1, m-1]

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int grid[100][100]; // Assuming that the this is the maximum size of grid.
int dp[100][100]; // At initial every value is -1;

int n, m;

int func(int i, int j) {
    if (i >= n || j >= m) {
        return INF; // Out of bounds
    }

    if (i == n - 1 && j == m - 1) {
        return grid[i][j]; //Value at that point
    }

    if (dp[i][j] != -1) {
        return dp[i][j]; // Returns the already computed result.
    }

    dp[i][j] = grid[i][j] + min(func(i, j + 1), func(i + 1, j));
    return dp[i][j];
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dp[i][j] = -1; // Initialize DP table with -1
        }
    }
    cout << func(0, 0) << endl;
}

int main() {
    solve();
    return 0;
}