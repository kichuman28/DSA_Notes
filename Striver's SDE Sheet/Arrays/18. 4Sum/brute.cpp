class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> temp;
        set<vector<int>> stt;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(i != j && i != k && i != l && j != k && j!= l && k != l){
                            long long sum = nums[i] + nums[j];
                            sum += nums[k];
                            sum += nums[l];
                            if(sum == target){
                                vector<int> ans = {nums[i], nums[j], nums[k], nums[l]};
                                sort(ans.begin(), ans.end());
                                stt.insert(ans);
                            }
                        }
                    }
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