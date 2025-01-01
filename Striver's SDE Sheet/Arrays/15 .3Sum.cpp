class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> temp;
        //Step 1: I need to sort the array
        sort(nums.begin(), nums.end());

        //Step 2: Traverse the array until you come across the last non-duplicate element
        for(int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            //Step 3: Perform the two pointer approach from here onwards
            
            int left = i+1;
            int right = n - 1;



            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum == 0){
                    temp.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--; //gotta do it one more time because I already have got a triplet with the current left & right
                }else if(sum > 0){
                    right--;
                }else{
                    left++;
                }
            }
        }

        return temp;
    }
};


//BRUTE FORCE
//Use 3 for loops
//When nums[i] + nums[j] + nums[k] == target, add it to temp and return it


//BETTER
//Use two for loops, for the third element we can figure it out by using num3 = target - (num1 + num2).
//We check if this num3 is present in the array. How do we find it? Using hashmap becuase then we don't have to linearly search it.
//One thing to notice is that all the indexes should be different. So start with the i & j for loop.
//While adding to the hashset, we add nums[j] to the hashset, and THEN we increment j. So this kinda makes sure the num3's index
//always lies between i & j and it'll never be equal to i or j.
//Then you sort the ans, add it to the set, then add it to the ans and return it. 


//Optimal - Neetcode's version.
//We use the two pointer approach from 2Sum II here. 
//First we sort the array. Example arr = [-3,3,4,-3,1,2], after sorting arr = [-3,-3,1,2,3,4]
//Then we move until the next number isnt a duplicate to prevent duplicate triplets. This is one of the reason we are 
//sorting the array. The second reason is to apply the two sum II solution over here, using the left & right pointers
//for the rest of the elements starting from -3 at index 1. In this way we get all 3 elements. 
