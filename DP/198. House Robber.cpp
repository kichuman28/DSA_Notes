class Solution {
    public:
    
        int maxCost(int index, vector<int> &nums, vector<int> &dp){
            if(index >= nums.size()){
                return 0;
            }
    
            if(dp[index] != -1) return dp[index];
    
            // int maxi = INT_MIN;
            int take = nums[index] + maxCost(index + 2, nums, dp);
            int notTake =  maxCost(index + 1, nums, dp);
    
            return dp[index] = max(take, notTake);
        }
    
    
        int rob(vector<int>& nums) {
            int index = 0;
            vector<int> dp(nums.size()+1, -1);
            return maxCost(index, nums, dp);
        }
    };