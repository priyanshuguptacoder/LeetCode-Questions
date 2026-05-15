class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        int num = k;

        while(true){
            if(s.find(num) != s.end()){
                num += k;
            }
            else{
                return num;
            }
        }
    }
};