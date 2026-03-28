class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //Step 1 : Push all boundary land cells
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){ //First row, Last Row, First Col, Last Col
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            //Traverse all 4 directions
            for(int k=0; k<4; k++){
                int ni = i + delRow[k];
                int nj = j + delCol[k];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m && vis[ni][nj] == 0 && grid[ni][nj] == 1){
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};