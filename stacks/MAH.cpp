#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

vector<int> NSR(vector<int>& arr, int n){
	vector<int> res;
	stack<int> st;
	for(int i = n - 1; i >= 0; i++){
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
			}
			else {
				res.push_back(st.top());
			}
		}
		st.push(arr[i]);
	}
	reverse(arr.begin(), arr.end());
	return res;
}

vector<int> NSL(vector<int>& arr, int n){
	vector<int> res;
	stack<int> st;
	for(int i = 0; i < n; i++){
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
			}
			else {
				res.push_back(st.top());
			}
		}
		st.push(arr[i]);
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
	vector<int> right = NSR(arr, n);
	vector<int> left = NSL(arr, n);
	vector<int> width(n);
	for(int i = 0; i < n; i++){
		width[i] = right[i] - left[i] - 1;
	}
	vector<int> area(n);
	for(int i = 0; i < n; i++){
		area[i] = arr[i] * width[i];
	}
	cout << *max_element(area.begin(), area.end()) << endl;
	return 0;
}
