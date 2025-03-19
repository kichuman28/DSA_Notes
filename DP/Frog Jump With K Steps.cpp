class Solution {
    public:
    
      int minCost(int index, int k, vector<int>& arr, int n, vector<int> &dp){
          if(index == n - 1){
              return 0;
          }
          
          if(dp[index] != -1) return dp[index];
          int mini = INT_MAX;
          for(int i = 1; i <= k; i++){
              
              int one = INT_MAX;
              if(index + i <= n-1){
                  one = abs(arr[index] - arr[index + i]) + minCost(index + i, k, arr, n, dp); 
              }
              mini = min(mini, one);
              
          }
          
          return dp[index] = mini;
      }
    
    
      int minimizeCost(int k, vector<int>& arr) {
          int index = 0;
          vector<int> dp(arr.size()+1, -1);
          return minCost(index, k, arr, arr.size(), dp);
      }
  };