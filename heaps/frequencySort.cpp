#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

struct cmp {
    bool operator()(const P& a, const P& b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

vector<int> frequencySort(vector<int>& arr, int n){
    unordered_map<int, int> mp;
    for(int val : arr){
        mp[val]++;
    }
    priority_queue<P, vector<P>, cmp> pq;
    vector<int> res;
    for(auto& it : mp){
        pq.push({it.second, it.first});
    }

    while(!pq.empty()){
        int freq = pq.top().first;
        int elem = pq.top().second;
        pq.pop();
        for(int i = 0; i < freq; i++){
            res.push_back(elem);
        }
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
    vector<int> res = frequencySort(arr, n);
    for(int val : res){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
