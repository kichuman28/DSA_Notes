class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;  
        for(int i = 0; i < n; i++){
            int value = target - nums[i];
            if(mpp.find(value) != mpp.end()){
                return {i, mpp[value]};
            }
            mpp[nums[i]] = i;
        }

        return {-1,-1};
    }
};

//Brute Force
//Use two for loops, if sum of nums[i] + nums[j] add up to target, add them to the vector & return it.
//TC = O(N^2)

//Better
//Sort the array
//Maintain two pointers, one from the beginning and one from the end.
//Add the values of nums[left] & nums[right].
//If value > target, decrement right
//If value < target, increment left
//When it becomes equal, store it in vector and return it.
//TC = O(NLogN)
//Can't use, once sorted the index changes for the answer while returning. 


//Optimal
//Maintain a hashmap. 
//We know 2 + 7 = 9. So first when we reach 2 in the array, check for the value by doing target - nums[i].
//Here it is 9 - 2 = 7.
//Check if it is there in the map. Since we are doing it for the first time, no.
//Add mpp[2] = 0.       here 0 is the index.
//Next iteration, nums[i] is 7. So when we do target - nums[i] => 9 - 7 = 2.
//We check if this 2 is present in the map. Turns out it is. 
//So we return it's index, which is mpp[value] and the current index, which is i. {mpp[value], i}.
