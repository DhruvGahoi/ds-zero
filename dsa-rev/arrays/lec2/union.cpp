#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    
    vector<int> unionArr;
    
    while(i < n && j < m){
        if(a[i] <= b[j]){
            if(unionArr.empty() || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        } else {
            if(unionArr.empty() || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(j < m){
        if(unionArr.empty() || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while(i < n){
        if(unionArr.empty() || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<int> result = sortedArray(a, b);

    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}