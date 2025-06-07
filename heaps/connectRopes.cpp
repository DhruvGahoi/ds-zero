#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr, int n){
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int cost = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }

    return cost;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << minCost(arr, n);
    return 0;
}
