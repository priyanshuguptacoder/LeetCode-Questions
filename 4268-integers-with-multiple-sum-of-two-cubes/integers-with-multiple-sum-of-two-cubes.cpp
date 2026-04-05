class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp; //Number and freq

        int limit = pow(n , 1.0/3) + 1; //Cube root of n

        for(int a=1; a<=limit; a++){
            for(int b=a; b<=limit; b++){
                int x = a*a*a + b*b*b;

                if(x > n){
                    break;
                }
                mp[x]++; //Because atleast two pair should exist
            }
        }

        vector<int> ans;
        for(auto &p : mp){
            if(p.second >= 2){
                ans.push_back(p.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};