#include<bits/stdc++.h>
#include <deque>
using namespace std;

// deque<T> dq;

void printD(deque<int>& dq){
	for(auto x : dq){
		cout << x << " ";
	}
	cout << endl;
}

int main(){
	deque<int> dq1; // empty deque
	deque<int> dq2(3, 4); // 4 4 4
	deque<int> dq3 =  {1, 4, 2, 3, 5};

	// 1. Inserting elements
	dq.push_back(5); // inserting at back
	dq.push_front(0); // inserting at front

	auto it = dq.begin() + 2;
	dq.insert(it, 11); // insert at third position.
	
	// 3. Accessing Elements
	cout << dq[2] << endl;
	cout << dq.front() << endl;
	cout << dq.back() << endl;

	// 4. Updating Elements
	dq[2] = 8;
	cout << dq[2] << endl;

	// 5. Traversing
	// Similar to the print function.
	
	// 6. Deleting Elements
	dq.pop_back(); // removing from back
	dq.pop_front(); // removing from front
	dq.erase(dq.begin());

	// 7. Copying elements from one dq to another.
	copy(oldDeque.begin(), oldDeque.end(), newDeque.begin());

	// 8. Fetching elements from particular index
	dq.at(2);
	dq1.swap(dq2);

	// 9. Sorting the deque
	sort(dq.begin(), dq.end());

	dq.clear(); // Clear the dq.
	
	reverse(dq.begin(), dq.end());t
}

// Removing and Inserting at some arbitary postion gives O(n).
