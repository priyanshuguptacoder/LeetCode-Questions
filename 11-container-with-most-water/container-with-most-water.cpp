class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0, end = n-1;
        int area = 0;
        int h = 0, b = 0;
        int maxi = -1;
        
        while(st < end){
            h = min(height[st], height[end]);
            b = end - st;
            area = h * b;
            maxi = max(maxi, area);
            
            if(height[st] < height[end]){
                st++;
            }
            else{
                end--;
            }
        }
        return maxi;
    }
};