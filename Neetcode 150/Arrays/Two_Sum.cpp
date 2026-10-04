class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int first, second;
        
        unordered_map <int, int> mpp;

        for (int i = 0; i < n; i++){
            int value = target - nums[i];
            if(mpp.find(value) != mpp.end()){
                return{i, mpp[value]};
            }
            mpp[nums[i]] = i; //The logic is the element I am looking for right now should not be there in the map. Only add it after checking. 
        }

        return {};
    }
};

//Approach A: Two nested for loops, TC = O(n^2)
//Approach B: I have the target. If I subtract x from target I can find y. I just have to check if y exists and return it's index. I can maybe create a hashmap where the keys are elements and their values are indices. I iterate through the array, find target - x, check if it's there in the hashmap and if yes return it's index. TC = O(N)

//https://leetcode.com/problems/two-sum/