class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        //Proper Triangle formation
        for(int i=0; i<n; i++){
            dp[i].resize(i+1); //It will create a dp of i+1 elements for index i    
        }

        //Base Case Foramtion for last row
        for(int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        //Fill from bottom to top
        //last row is base case so we already created dp so started from n-1
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
};