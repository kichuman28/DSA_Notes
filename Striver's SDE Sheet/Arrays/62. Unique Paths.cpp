class Solution {
public:

    int maxPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int right = 0;
        if(j + 1 < n){
            right += maxPaths(i, j+1, m, n, dp);
        }
        int down = 0;
        if(i + 1 < m){
            down += maxPaths(i+1, j, m, n, dp);
        }

        return dp[i][j] = down + right;
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[0][0] = 0;
        return maxPaths(0, 0, m, n, dp);
    }
};