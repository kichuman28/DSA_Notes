class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxi = INT_MIN;
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]) continue;      //Need to handle duplicates
            if(nums[i+1] - nums[i] == 1) count++;
            else{
                maxi = max(maxi, count);
                count = 1;
            }
        }

        maxi = max(maxi, count);

        return maxi;
    }
};


//Brute Force
//Sort the array
//maintain a count until the sequence breaks off
//return the count
//TC = O(NlogN) + O(N)

//Note: Multiple Sequences can be present. So each time a sequence breaks off we need to find the count of the 
//supposed new sequence.