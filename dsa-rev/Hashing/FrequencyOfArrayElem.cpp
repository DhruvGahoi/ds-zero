#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void countFrequencies(vector<int>& arr, int N) {
    unordered_map<int, int> freqMap;

    // Count the frequencies of elements from 1 to N
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= N) {
            freqMap[arr[i]]++;
        }
    }

    // Print the frequencies
    for (int i = 1; i <= N; i++) {
        cout << "Frequency of " << i << ": " << freqMap[i] << endl;
    }
}

int main() {
    int N = 5;
    vector<int> arr = {1, 3, 2, 2, 4, 3, 5, 2};

    countFrequencies(arr, N);

    return 0;
}