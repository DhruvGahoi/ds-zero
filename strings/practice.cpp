#include<bits/stdc++.h>
using namespace std;

int main(){
	string s = "hellooo";
	s.push_back('z'); // append char
	s.pop_back(); // remove from last

	// s += "abc"; // append at end
	s.insert(2, "ZZ"); // append at some posn
	s.erase(2, 2); // (index, count)
	// s.clear(); // makes it empty
	string sub = s.substr(2, 3); // from idx 2, length 3
	
	int i = s.find("lo"); // return index 3
	cout << i << "\n";
	int l = s.rfind("l");
	cout << l << "\n";
	// s.find("xyz"); // string::npos if not found
	
	// ------ getline: reads whole line including spaces
	// unlike cin >> s which stops at spaves
	string line;
	getline(cin, line);
	
	getline(cin, line, ','); // puts a delimiter, reads until ','
	

	// ------- stringstream: used for parsing strings(tokenizing input)
	
	string input = "10 20 30";
	stringstream ss(input);
	int x;
	while(ss >> x){
		cout << x << " "; // 10 20 30
	}
	cout << s; 

	string date = "27 Oct 2001";
	stringstream st(date);
	string day, month, year;
	ss >> day >> month >> year;

	cout << day << " " << month << " " << year << "\n";

	// -------- string::npos
	if (s.find("xyz") == string::npos) {
    		cout << "Not found\n";
	}

	string numStr = "1234";
	int t = stoi(numStr);
	long long y = stoll(numStr);
	double d = stod("3.15");

	int z = 456;
	string str = to_string(z);

	const char* c = s.c_str();
	char arr[100];
	strcpy(arr, s.c_str());


	// if (s.find("abc") != string::npos) cout << "Found!";
	//
	// Parse CSV input
	string line = "apple,banana,cherry";
	stringstream sp(line);
	string item;
	while(getline(sp, item, ',')) {
    		cout << item << "\n";
	}


	
}
