class Solution {
public:

    void findAllCombo(int index, vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        findAllCombo(index + 1, ans, temp, nums);
        temp.pop_back();
        findAllCombo(index + 1, ans, temp, nums);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        findAllCombo(index, ans, temp, nums);
        return ans;
    }
};