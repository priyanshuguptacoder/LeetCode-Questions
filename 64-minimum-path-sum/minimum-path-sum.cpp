class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[0][0];
                }

                else{
                    //Like in anycase left exist and any other right exist so we are using INT_MAX, so it can becomes INT_MAX so it can become min
                    int up = grid[i][j];
                    if(i > 0){
                        up += prev[j];
                    }
                    else{
                        up = INT_MAX;
                    }

                    int left = grid[i][j];
                    if(j > 0){
                        left += curr[j-1];
                    }
                    else{
                        left = INT_MAX;
                    }
                    
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};