    class Solution {
    public:
        int waysToSplitArray(vector<int>& nums) {
            int n = nums.size();
            int count = 0;

            //Make the prefixSum array.
            vector<long long> prefixSum(n, 0);
            long long sum = 0;
            for(int i = 0; i < n; i++){
                sum += nums[i];
                prefixSum[i] = sum;
            }

            //Traverse the array till n-1.
            for(int i = 0; i < n-1; i++){
                long long leftSum = prefixSum[i];
                long long rightSum = prefixSum[n-1] - prefixSum[i];

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
//TC = O(N^2)

//Optimal
//Use the prefix sum method to calculate the sum till a particular index so we don't have to recompute it every time.
//For each index we reach, take the leftSum = prefixSum[i], rightSum = prefixSum[n-1] - prefixSum[i].
//Do the standard check, increment count and then return it.
//TC = O(N)