class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> temp;
        set<vector<int>> stt;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                set<long long> mpp;
                for(int k = j+1; k < n; k++){
                    long long sum = nums[i] + nums[j]; 
                    sum += nums[k];
                    long long num4 = target - sum;
                    if(mpp.find(num4) != mpp.end()){
                        vector<int> ans = {nums[i], nums[j], nums[k], (int)num4};
                        sort(ans.begin(), ans.end());
                        stt.insert(ans);
                    }
                    mpp.insert(nums[k]);
                }
            }
        }

        for(auto it: stt){
            temp.push_back(it);
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