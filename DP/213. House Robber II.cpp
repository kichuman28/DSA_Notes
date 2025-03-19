class Solution {
    public:
    
        int maxCost(int index, vector<int> &nums, int n, vector<int> &dp){
            if(index >= n){
                return 0;
            }
    
            if(dp[index] != -1) return dp[index];
            int take = nums[index] + maxCost(index + 2, nums, n, dp);
            int notTake = maxCost(index + 1, nums, n, dp);
    
            return dp[index]=max(take, notTake);
        }
    
        int rob(vector<int>& nums) {
            int index = 0;
            int n = nums.size();
    
            vector<int> dp1(n, -1);
            vector<int> dp2(n, -1);
            if(n == 1) return nums[0];
            vector<int> temp1, temp2;
            for(int i = 0; i < n-1; i++) temp1.push_back(nums[i]);
            for(int i = 1; i < n; i++) temp2.push_back(nums[i]);
    
            int ans1 = maxCost(0, temp1, n-1, dp1);
            int ans2 = maxCost(0, temp2, n-1, dp2);
    
            return max(ans1, ans2);
        }
    };