#include <iostream>
#include <vector>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    if (k == 0) {
        return vector<int>(n, 0); // If k == 0, return all zeros
    }

    vector<int> extendedCode(code.begin(), code.end());
    extendedCode.insert(extendedCode.end(), code.begin(), code.end()); // Extend array to handle circular nature

    // Create prefix sum array
    vector<int> prefixSum(extendedCode.size() + 1, 0);
    for (int i = 1; i <= extendedCode.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + extendedCode[i - 1];
    }

    vector<int> result(n, 0);
    if (k > 0) {
        for (int i = 0; i < n; i++) {
            result[i] = prefixSum[i + k + 1] - prefixSum[i + 1];
        }
    } else { // k < 0
        k = -k;
        for (int i = 0; i < n; i++) {
            result[i] = prefixSum[i + n] - prefixSum[i + n - k];
        }
    }

    return result;
}

int main() {
    vector<int> code = {5, 7, 1, 4};
    int k = 3;

    vector<int> decrypted = decrypt(code, k);
    cout << "Decrypted Code: ";
    for (int num : decrypted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}