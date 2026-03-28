class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();

        vis[i][j] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int k=0; k<4; k++){
            int ni = i + delRow[k];
            int nj = j + delCol[k];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && board[ni][nj] == 'O'){
                dfs(ni, nj, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        //Step 1 : Traverse boundary
        for(int j=0; j<m; j++){ //First Row
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, board, vis);
            }

            if(board[n-1][j] == 'O' && !vis[n-1][j]){ //Last Row
                 dfs(n-1, j, board, vis);
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){ //First Column
                dfs(i, 0, board, vis);
            }

            if(board[i][m-1] == 'O' && !vis[i][m-1]){ //Last Column
                dfs(i, m-1, board, vis);
            }
        }

        //Step 2 : Flip unvisited 'O' to 'X''
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};