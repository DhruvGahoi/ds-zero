class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int originalColor = image[sr][sc];

        if(originalColor == color) return image;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> que;
        que.push({sr, sc});
        image[sr][sc] = color;

        while(!que.empty()){
            auto curr = que.front();
            que.pop();

            int u = curr.first;
            int v = curr.second;

            for(auto& dir : directions){
                int nRow = u + dir.first;
                int nCol = v + dir.second;

                if(nRow >= 0 && nCol >= 0 && nRow < row && nCol < col && image[nRow][nCol] == originalColor){
                    image[nRow][nCol] = color;
                    que.push({nRow, nCol});
                }
            }
        }

        return image;
    }
};