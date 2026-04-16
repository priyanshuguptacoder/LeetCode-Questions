class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        //Take last row as initial dp
        vector<int> front = triangle[n-1];
        
        //Build from bottom to top
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int down = triangle[i][j] + front[j]; //Fornt gives down element(i+1, j) and i+1 is front
                int diagonal = triangle[i][j] + front[j+1]; //This front gives element(i+1, j+1) and i+1 is front

                front[j] = min(down, diagonal); //We did not update front after loop because we want till i its updated
            }
        }
        return front[0];
    }
};