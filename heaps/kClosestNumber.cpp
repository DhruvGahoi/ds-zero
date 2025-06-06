#include<bits/stdc++.h>
#include <queue>
using namespace std;
typedef pair<int, int> P;
vector<int> kClosestNumber(vector<int>& arr, int n, int k, int x){
    vector<int> res;
    priority_queue<P> pq;
    for(int i = 0; i < n; i++){
        pq.push({abs(arr[i] - x), arr[i]});
        if(pq.size() > k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }

    sort(res.begin(), res.end());
    return res;

}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k, x;
    cin >> k >> x;
    vector<int> res = kClosestNumber(arr, n, k, x);
    for(int val : res){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
