class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> result(row, vector<int>(col, INT_MAX));
        queue<pair<int, int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int u = curr.first;
            int v = curr.second;

            for(auto& dir : directions){
                int nRow = u + dir.first;
                int nCol = v + dir.second;

                if (nRow >= 0 && nCol >= 0 && nRow < row && nCol < col) {
                    if (result[nRow][nCol] > result[u][v] + 1) {
                        result[nRow][nCol] = result[u][v] + 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }

        return result;
    }
};