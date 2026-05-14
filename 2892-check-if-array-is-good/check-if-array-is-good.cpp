class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        if(nums[0] != 1){
            return false;
        }
        
        int start = 1, end = nums[n-1];
        for(int i=1; i<n; i++){
            
            if(start + 1 == nums[i]){
                start++;
            }
            else if(end == nums[i]){
                continue;
            }
            else{
                return false;
            }
        }
        
        if(start + 1 == n && end == n - 1){
            return true;
        }
        else{
            return false;
        }
    }
};