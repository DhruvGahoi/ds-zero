#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> kSortedArray(vector<int> arr, int k, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            res.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
    }

    return res;
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
    vector<int> result = kSortedArray(arr, k, n);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

