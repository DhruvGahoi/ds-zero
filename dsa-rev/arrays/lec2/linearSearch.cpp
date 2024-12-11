#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int n, int k){
    for(int i = 0; i < n; i++){
        if(arr[i] == k) return i;
    }
    return -1;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << linearSearch(arr, n, k);
    return 0;
}