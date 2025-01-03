class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        map<int, int> mpp;        
        int maxi = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == k){
                maxi = max(maxi, i + 1);
            }else if(mpp.find(sum - k) != mpp.end()){   
                maxi = max(maxi, i - mpp[sum - k]);
            }
            
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;               //We need this condtion for test cases with 0.
                                            //Do a dry run with input [2,0,0,3], k = 3 without this condition to understand
                                            //tldr: We cannot update the key if it exists. Here 2 exists, so when you add the next element, i.e 0 we still get 2. So we are again updating mpp[2] = 1. Before mpp[2] = 0. This will continue until mpp[2] = 2. This is correct, but we want the longest length, not the shortest. So we must only update the key in the map if it isn't already not there, hence the condition. 
            }    
        }
        
        return maxi;
    }
};


//Optimal
//We are kinda using a reverse engineering technique over here.
//The same concept of prefixSum we did in potd jan 2 & 3. But instead of storing it in an array we store it in a hashmap.
//Each time we traverse the array we keep track of the sum. 
//First if condition: Check if the sum is equal to k. If it is then update the length.
//Second if condition: Check if sum - k is present in the hashmap or not. The hashmap consists of the prefix sums till the
//current index. If in case sum - k is present then it means I'll get k if I remove sum - k. So you update the count.
//For example nums = [1,2,1,2,1], k = 3. Sum till index 3 is 1+2+1+2 = 4. So to check if k = 3 exists as a subarray inbetween
//this all I have to check is sum - k, i.e 4 - 3 = 1. Turns out 1 is present at index 0, so if I subtract that I'll get k = 3.
//So now we can update the length. 
//So each time we add the sum, I also add in the prefix sum and it's corresponding index into the hashmap. 
//The above step is done after checking if the current sum - k is present in the hashmap or not.