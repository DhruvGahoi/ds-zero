#include<bits/stdc++.h>
using namespace std;
typedef  pair<int, int> P;

vector<P> kClosestPoints(vector<P>& pairs, int n, int k){
    vector<P> res;
    priority_queue<pair<int, P>> pq;
    for(int i = 0; i < n; i++){
        int x = pairs[i].first;
        int y = pairs[i].second;
        int dist = x * x + y * y;
        pq.push({dist, pairs[i]});
        if(pq.size() > k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
};

int main(){
    int n;
    cin >> n;
    vector<P> pairs(n);
    for(int i = 0; i < n; i++){
        cin >> pairs[i].first >> pairs[i].second;
    }
    int k;
    cin >> k;
    
    vector<P> res = kClosestPoints(pairs, n, k);
    
    for(auto& p : res){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
