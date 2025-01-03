class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        //Traverse the array till n-1.
        for(int i = 0; i < n-1; i++){
            int leftSum = 0;
            int rightSum = 0;

            for(int j = 0; j <= i; j++) leftSum += nums[j];
            for(int k = i+1; k < n; k++) rightSum += nums[k];

            if(leftSum >= rightSum){
                count++;
            }
        }

        return count;
    }
};


//Brute Force
//Traverse the array for each split index i.
//Calculate the sum of the left half and the right half.
//If leftSum >= rightSum, we got a valid split. Increment the count by one.
//Return the count