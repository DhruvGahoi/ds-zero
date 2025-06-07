#include<bits/stdc++.h>
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
    int k1, k2;
    cin >> k1 >> k2;
    int el1 = kthSmallest(arr, n, k1);
    int el2 = kthSmallest(arr, n, k2);
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > el1 && arr[i] < el2){
            sum += arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}
