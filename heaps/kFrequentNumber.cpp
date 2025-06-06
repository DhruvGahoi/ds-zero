#include<bits/stdc++.h>
#include <queue>
using namespace std;
typedef pair<int, int> P;

vector<int> topKFreq(vector<int>& arr, int n, int k){
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    vector<int> res;
    priority_queue<P, vector<P>, greater<P>> pq;
    for(auto& it : mp){
        pq.push({it.second, it.first});
        if(pq.size() > k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
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
    vector<int> res = topKFreq(arr, n, k);
    for(int val : res){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
