#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr, int n){
	vector<int> res;
	stack<int> st;
	for(int i = n - 1; i >= 0; i--){
		if(st.size() == 0){
			res.push_back(-1);
		}
		else if(st.size() > 0 && st.top() < arr[i]){
			res.push_back(st.top()); 
		}
		else if(st.size() > 0 && st.top() >= arr[i]){
			while(st.size() > 0 && st.top() >= arr[i]){
				st.pop();
			}
			if(st.size() == 0){
				res.push_back(-1);
			} else {
				res.push_back(st.top());
			}
		}

		st.push(arr[i]);
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
	vector<int> res = solve(arr, n);
	for(int val : res){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
