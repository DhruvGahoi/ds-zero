#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &arr, int n) {
  set<int> st;
  for(int i = 0; i < n; i++){
    st.insert(arr[i]);
  }
  return st.size();
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << removeDuplicates(arr, n);
    return 0;
}