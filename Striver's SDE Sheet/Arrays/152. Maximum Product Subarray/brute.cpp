class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            int product = 1;
            for(int j = i; j < n; j++){
                product = product * nums[j];
                maxi = max(maxi, product);
            }
        }

        return maxi;
    }
};

//Brute Force
//Use two for loops, consider all subrarray's products, find the maxi, return it.
//TC = O(N^2).