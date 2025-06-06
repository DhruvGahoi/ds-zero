#include<bits/stdc++.h>
#include <queue>
using namespace std;

int kthSmallest(vector<int>& arr, int n, int k){
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << kthSmallest(arr, n, k);
    return 0;
}
