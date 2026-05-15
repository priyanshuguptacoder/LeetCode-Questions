class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int res = k;
        for(int num : nums){
            if(num == res){
                res += k;
            }
        }

        return res;
    }
};