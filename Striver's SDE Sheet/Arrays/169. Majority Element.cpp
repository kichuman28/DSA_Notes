class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = nums[0];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == element){
                count++;
            }else{
                count--;
                if(count == 0){
                    element = nums[i];
                    count = 1;
                }
            }
        }
        return element;
    }
};


//Brute Force:
//Maintain a hashmap with key as num[i] and values as the frequency of nums[i].
//Traverse the hashmap, return the first element with frequency > n/2.
//TC = O(2^n), SC = O(N).

//Optimal : Moore's Voting Algorithm
//This algorithm can only be used if the element exists more than n/2 times, which in this qs is guaranteed. 
//So what we do is that we maintain a counter for each element in the array. 
//We increment the counter by one each time we find the same element. If we find a different one we subtract.
//The moment the freq becomes 0 as we keep on subtracting, replace the answer with the new element we got. 
//After the whole loop is done, return the answer. We are bound to get one because the qs says 
//"You may assume that the majority element always exists in the array."
//TC = O(N), SC = O(1).