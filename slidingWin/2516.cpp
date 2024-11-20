------------------------Recursive Approach---------------------------

class Solution {
public:

    int result = INT_MAX;

    void solve(string s, int k, int i, int j, int minutes, vector<int> freq) {
        if(freq[0] >= k && freq[1] >= k && freq[2] >= k) {
            result = min(result, minutes);
            return;
        } 
        if(i > j) { // all character visited
            return;
        }

        vector<int> tempLeft = freq;
        tempLeft[s[i] - 'a'] += 1; //Basically deletes the leftmost element and we removed 'a' becuase if the char is a simply return 0th index if its b returns 1 index and so on...  
        solve(s, k, i+1, j, minutes+1, tempLeft);
        vector<int> tempRight = freq;
        tempRight[s[j] - 'a'] += 1;
        solve(s, k, i, j-1, minutes+1, tempRight);

    }

    int takeCharacters(string s, int k){
        vector<int> freq(3, 0);
        int i = 0;
        int j = s.length() - 1;
        int minutes = 0;
        solve(s, k, i, j, minutes, freq);

        return result ==  INT_MAX ? -1 : result;
    }
};


---------------------------Sliding Window------------------------------------

class Solution {
public:
    int takeCharacters(string s, int k) {

        int n = s.length();
        
        int countA = 0; // Initally we are deleting this , and in while loop we are reducing its value for checking the min deletion >= k, if its not then we shrink the window.
        int countB = 0;
        int countC = 0;

        int notDeletedWindowSize = 0;

        for(char ch : s) {
            if(ch == 'a') {
                countA++;
            } else if(ch == 'b') {
                countB++;
            } else {
                countC++;
            }
        }

        if(countA < k || countB < k || countC < k) {
            return -1;
        }
        
        int i = 0;
        int j = 0;

        while(j < n) {
            if(s[j] == 'a'){
                countA--;
            } else if(s[j] == 'b'){
                countB--;
            } else if(s[j] == 'c'){
                countC--;
            }

            // If deletion of any counter is < k, then shrink the window and bring them back
            while(i <= j && (countA < k || countB < k || countC < k)) {
                // ith pointer move to left
                if(s[i] == 'a'){
                    countA++;
                } else if(s[i] == 'b'){
                    countB++;
                } else if(s[i] == 'c'){
                    countC++;
                }
                i++;
            }

            notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
            j++;
        }

        return n - notDeletedWindowSize; // minutes
    }
};