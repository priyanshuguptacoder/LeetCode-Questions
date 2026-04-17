class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j]; //First row as base case
        }

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];

                int ld = matrix[i][j];
                if(j > 0){
                    ld += dp[i-1][j-1];
                }
                else{
                    ld += 1e9;
                }

                int rd = matrix[i][j];
                if(j < n-1){
                    rd += dp[i-1][j+1];
                }
                else{
                    rd += 1e9;
                }

                dp[i][j] = min(up, min(ld, rd));
            }
        }

        int mini = 1e9;
        for(int j=0; j<n; j++){
            mini = min(mini, dp[n-1][j]); //Last Rom me maximum kon hai wo answer hoga
        }
        return mini;
    }
};