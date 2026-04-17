class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0);

        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j]; //First row as base case
        }

        for(int i=1; i<m; i++){
            vector<int> curr(n, 0);

            for(int j=0; j<n; j++){
                int up = matrix[i][j] + prev[j];

                int ld = matrix[i][j];
                if(j > 0){
                    ld += prev[j-1];
                }
                else{
                    ld += 1e9;
                }

                int rd = matrix[i][j];
                if(j < n-1){
                    rd += prev[j+1];
                }
                else{
                    rd += 1e9;
                }

                curr[j] = min(up, min(ld, rd));
            }
            prev = curr;
        }

        int mini = 1e9;
        for(int j=0; j<n; j++){
            mini = min(mini, prev[j]); //Last Rom me maximum kon hai wo answer hoga
        }
        return mini;
    }
};