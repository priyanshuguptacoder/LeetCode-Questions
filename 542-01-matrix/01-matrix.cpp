class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>> q;

        //Step 1 : Push all 0s into queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        
        //Step 2 : BFS
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dis[row][col] = steps;

            for(int i=0; i<4; i++){ //For Top, Bottom, Left, Right
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps+1});
                }
            }
        }
        return dis;
    }
};