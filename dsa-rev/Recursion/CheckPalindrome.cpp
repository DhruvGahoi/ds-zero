#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string &str, int i, int j){
    if(i > j) return true; // Base case to stop recursion
    if(str[i] != str[j]) return false; // If characters at start and end are not equal
    return isPalindrome(str, i+1, j-1);
}

int main(){
    string str;
    cout << "Enter the string : ";
    cin >> str;
    if(isPalindrome(str, 0, str.length()-1)){
        cout << "The following string is a palindrome.";
    } else {
        cout << "The given string is not a palindrome.";
    }
    return 0;
}