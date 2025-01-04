class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        //Step 1: I need a hashmap
        map<int, int> mpp;

        //I need to add 0 as a prefix sum with it's count as one.
        mpp[0] = 1;

        //Traverse the array, keep a track of the count.
        int count = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];

            //Check if sum - k is present in the hashmap or not
            if(mpp.find(sum - k) != mpp.end()){
                count += mpp[sum - k];
            }

            mpp[sum]++; //Map is already made with default values as 0, dont worry about this.

        }

        return count;
    }
};

//Brute Force
//Use two for loops, find the sum of every possible sub array, if the sum equals k then increment the count, return it.
//TC = O(N^2).


//Optimal Method
//We use the same concept of prefix sum here. 
//What can confuse you here is how this differs from finding the subarray with maximum length with sum = k
//As in that problem, we only needed to check if sum - k exists, then we can update the count.
//In the hashmap we used the sum and the index where it occured {sum, index}

//Here things are a litte different. Mainly we need to find how many times sum - k occurs in the given subarray. 
//Read that again carefully. 
//Like for another subarray if the same sum - k occurs again then it means there are two subarrays that can give us a sum=k
//Hence the reason we are using a count variable. 
//The map structure would look something like {sum, count}.
//sum - k is some random number than might be there in the given subarray. In order to check if sum - k is present in the 
//present sub array, we have to check the prefixSum because I NEED A CONTIGOUS SUBARRAY WITH SUM = K and that's only possible
//if I equate sum - k as some prefixSum in the given subarray, whose count I am tracking in the hashmap as well for future
//subarrays. Manasilayo?


//Step 0: Add 0 as a prefix sum to the hashmap becuase in case we get sum = k, sum - k = 0, so that's a prefix sum which 
//occurs once, there's no other way to add it into the hashmap as we are adding elements from the array into the map only. 
//So add mpp[0] = 1.
//Step 1: Keep a variable called sum to calculate the prefixSum at every stage nums[i].
//Step 2: Check if sum - k is present in the hashmap. If it does, increment the count with mpp[sum - k].
//Step 3: Add the current prefixSum's occurence into the hashmap.
//Step 4: Return the count.
