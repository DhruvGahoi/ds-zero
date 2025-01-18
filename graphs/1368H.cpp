
/************************************************************ C++ ************************************************/
//Approach-1 (Backtracking DFS to try all paths) - TLE
//T.C : O(4^(m*n))
//S.C : O(m*n)

// class Solution {
// public:
//     vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//     int m, n;

//     int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int cost) {
//     if (i == m - 1 && j == n - 1) {
//         return cost;
//     }

//     visited[i][j] = true;

//     int minCost = INT_MAX;
//     for (int dir_i = 0; dir_i <= 3; dir_i++) {
//         int u = i + dir[dir_i][0];
//         int v = j + dir[dir_i][1];

//         if (u >= 0 && u < m && v >= 0 && v < n && !visited[u][v]) {
//             // Corrected nextCost calculation
//             int nextCost = cost + ((grid[i][j] - 1 != dir_i) ? 1 : 0);
//             minCost = min(minCost, dfs(u, v, grid, visited, nextCost));
//         }
//     }

//     visited[i][j] = false;
//     return minCost;
// }


//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         // explore all paths by backtrackoing
//         return dfs(0, 0, grid, visited, 0);  
//     }
// };


//Approach-2 (Dijkstra's Algorithm) - Accepted
//T.C : O((m*n) * log(m*n))
//S.C : O(m*n)

class Solution {
public: 
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // minHeap

        pq.push({0, 0, 0});
        result[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop(); //log(size of pq)

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(result[i][j] < currCost){
                continue;
            }

            for(int dir_i = 0; dir_i <= 3; dir_i++){
                int u = i + dir[dir_i][0];
                int v = j + dir[dir_i][1];

                if(u >= 0 && u < m && v >= 0 && v < n){
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir - 1 != dir_i) ? 1 : 0);

                    int newCost = currCost + dirCost;

                    if(newCost < result[u][v]){
                        result[u][v] = newCost;
                        pq.push({newCost, u, v});
                    }
                }
            }
        }

        return result[m - 1][n - 1]; //min Cost to reach (m-1, n-1)

    }
};
