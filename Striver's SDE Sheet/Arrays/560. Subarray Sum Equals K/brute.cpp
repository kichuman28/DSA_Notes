class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }

        return count;
    }
};

//Brute Force
//Use two for loops, find the sum of every possible sub array, if the sum equals k then increment the count, return it.
//TC = O(N^2).

