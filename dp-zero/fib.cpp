#include<bits/stdc++.h>
using namespace std;

// Brute
int brute(int n){
	if(n <= 2){
		return 1;
	}
	return brute(n - 1) + brute(n - 2);
}

// Iterative DP
vector<int> dp(100, -1);

// Recursive DP
int recursive(int n){
	if(n <= 2) return 1;
	if(dp[n] != -1){
		return dp[n];
	}
	dp[n] = recursive(n - 1) + recursive(n - 2);
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	cout << brute(n) << "\n";
	// ---------------
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << "\n";
	// ---------------
	cout << recursive(n) << "\n";
}
