class Solution {
    public:
    
    
      int minValue(vector<int> &dp, int index, vector<int>& height){
          if(index == height.size()-1){
              return 0;
          }
  
          if(dp[index] != -1) return dp[index];
  
          int one = minValue(dp, index + 1, height) + abs(height[index] - height[index + 1]);
          
          int two = INT_MAX;
          if(index+2 < height.size()) two = minValue(dp, index + 2, height) + abs(height[index] - height[index + 2]);
          
          return dp[index] = min(one, two);
      }
    
    
      int minCost(vector<int>& height) {
          int n = height.size();
          int index = 0;
          vector<int> dp(n+1, -1);
          return minValue(dp, index, height);
      }
  };