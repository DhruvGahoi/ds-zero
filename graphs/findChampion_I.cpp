class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    inDegree[j]++;
                }
            }
        }

        vector<int> zeroInDegreeNodes;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                zeroInDegreeNodes.push_back(i);
            }
        }


        if (zeroInDegreeNodes.size() == 1) {
            return zeroInDegreeNodes[0];
        } else {
            return -1;
        }
    }
};