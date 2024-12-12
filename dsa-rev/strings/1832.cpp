class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> uniqueChars;
        for (char ch : sentence) {
            uniqueChars.insert(ch);
        }
        return uniqueChars.size() == 26;
    }
};

