class Solution {
private:
    double power(double a, long long b){
        if(b == 0){
            return 1;
        }
        
        double ans = power(a, b/2);

        if(b % 2 == 0){
            return ans * ans;
        }
        else{
            return a * ans * ans;
        }
    }

public:
    double myPow(double a, int exp) {
        long long b = exp;

        if(b < 0){
            a = 1/a;
            b = -b;
        }

        return power(a, b);
    }
};