class Solution {
    public:
    
        int stairs(vector<int> &dp, int n){
            if(n == 0 || n == 1){
                return 1;
            }
    
            if(dp[n] != -1) return dp[n];
    
            int one = stairs(dp, n-1);
            int two = stairs(dp, n-2);
    
            return dp[n] = one + two;
        }
    
        int climbStairs(int n) {
            vector<int> dp(n+1, -1);
            return stairs(dp, n);
        }
    };