#include<bits/stdc++.h>
#include <ios>
#include <iterator>
#include <set>
using namespace std;

// multiset<T, comp> ms;
// T : datatype of elements
// ms : name of the multiset
// comp : binary predicate function that tells multiset how to compare two elements in sorting, purely optional.

int main(){
	multiset<int> ms = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	// 1. Traversing
	for(auto it : ms){
		cout << it << " ";
	}
	return 0;

	// 2. Inserting 
	ms.insert(2);

	//  3. Accessing
	auto it1 = ms.begin();
	cout << *it1 << endl;
	auto it2 = next(it1, 2); // Access the third element
	
	// 4. Updating Elements
	// We cannot change the val once they are stored in the set.
	
	// 5. Finding Elements
	auto it = ms.find(3);
	if(it != ms.end()) cout << *it;
	else cout << "Not Found!";

	// 6. Erasing element
	ms.erase(3);

	// 7. Find all occurences of an Element in a ms.
	int target = 3;
	cout << "The element " << target << "occured at indices: ";

	auto it = ms.equal_range(3);
	for(auto i = it.first; i != it.second; i++){
		cout << distance(ms.begin(), i) << " ";
	}

	// 8. Initialize a Multiset with a Custom Comparator in C++
	auto comp = [&](const int& a, const int&b){
		return a > b;
	};

	multiset<int, decltype(comp)> customSet(comp);
	customSet.insert(5);
	customSet.insert(8);
	customSet.insert(3);
	// 8 5 3
	
	// Can also insert pairs in multiset.
	
	// 9. Swapping in multiset.
	multiset<int> ms1{1, 2, 3, 4, 5};
	multiset<int> ms2{5, 6, 7, 8, 9};

	ms1.swap(ms2);

	// 9. Frequency
	int freq = ms.count(3);
	cout << "The frequency of 3 is : "<< freq;
}
