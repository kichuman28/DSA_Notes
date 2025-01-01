class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> temp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j-1] == nums[j]) continue;

                int left = j + 1;
                int right = n - 1;

                while(left < right){
                    long long sum = nums[i] + nums[j];
                    sum += nums[left] + nums[right];
                    if(sum == target){
                        vector<int> ans = {nums[i], nums[j], nums[left], nums[right]};
                        temp.push_back(ans);
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }else if(sum > target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }

        return temp;
    }
};

//Brute force
//Use 4 for loops, if nums[i] + nums[j] + nums[k] + nums[l] == target, 
//sort them, Add all of it to a set for getting only unique ones and then put it into a vector & return it.
//TC = O(N^4).

//Hashset approach
//Use only 3 loops, for the fourth element you subtract the sum of first 3 from target.
//Check if it is there in hashset, if yes, sort, add to set
//Insert nums[l] into the hashset.
//Put all the vectors in the set to another vector of vectors and return it.
//TC = O(N^3).

//Optimal approach
