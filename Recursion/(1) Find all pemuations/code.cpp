class Solution {
public:

    void findPerm(vector<int>& nums, vector<vector<int>> &temp, vector<int> &vis, vector<int>& ans){
        if(ans.size() == nums.size()){
            temp.push_back(ans);
        }

        for(int i = 0; i < nums.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                ans.push_back(nums[i]);
                findPerm(nums, temp, vis, ans);
                ans.pop_back();
                vis[i] = 0;
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<vector<int>> temp;
        findPerm(nums, temp, vis, ans);
        return temp;

    }
};

//Approach (Recursive)
//(1) Maintain a vector as a "visited data strucure" for each number in the array.
//(2) Check whether each element in the array is visited or not (1 or 0) using a for loop. If it is not visited mark it as visited, add the number to the array and call the function again.
//(3)After it reaches the base case and one combination is found it comes back. Pop out the last added element. Mark it as unvisited in the visited array.
// BASE CASE : If the size of the array where you add the elements is equal to the size of the given array then that means that combination is over. Add it to the matrix. 

//TC = O(N! * N) the second N is for the for loop in the recursive function.
//SC = O(N) for visited array.
