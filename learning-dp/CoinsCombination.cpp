#include<iostream>
#include <vector>
using namespace std;

int numberOfWays(int x, vector<int>& coins) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= x; j++) {
        for (int coin : coins) {
            if (j - coin >= 0) {
                dp[j] += dp[j - coin];
            }
        }
    }

    return dp[x];
}

int main() {
    int x = 9;
    vector<int> coins = {2, 3, 5};

    cout << "Number of ways to make sum " << x << ": " << numberOfWays(x, coins) << endl;

    return 0;
}