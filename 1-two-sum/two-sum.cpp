class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        int n = nums.size();

        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int st = 0, end = n-1;
        int sum = INT_MIN;

        while(sum != target){
            sum = v[st].first + v[end].first;

            if(sum == target){
                return {v[st].second, v[end].second};
            }
            else if(sum > target){
                end--;
            }
            else{
                st++;
            }
        }
        return {};
    }
};