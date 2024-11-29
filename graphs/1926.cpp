class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();

        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]}); 
        maze[entrance[0]][entrance[1]] = '+'; 

        int steps = 0;

        while (!que.empty()) {
            int n = que.size();
            steps++;

            while (n--) {
                auto curr = que.front();
                que.pop();

                int u = curr.first;
                int v = curr.second;

                for (auto dir : directions) {
                    int nRow = u + dir[0];
                    int nCol = v + dir[1];

                    if(nRow >= 0 && nRow < row && nCol >= 0 && nCol < col && maze[nRow][nCol] == '.') {
                        if (nRow == 0 || nRow == row - 1 || nCol == 0 || nCol == col - 1) {
                            return steps;
                        }
                        maze[nRow][nCol] = '+';
                        que.push({nRow, nCol});
                    }
                }
            }
        }
        return -1;
    }
};