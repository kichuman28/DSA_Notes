#include<bits/stdc++.h>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]] += 1;
            if(mpp[nums[i]] > 1) return true;
        }

        return false;
    }
};


//3 Approaches

//A) Sort the elements, then check if the next element is equal to the current element. If yes, return true. Else, return false.
//B) Use a set to store the elements and simulataneously check if the element is already present in the set. If yes, return true. Else, return false.
//C) Use a set to store the elements. If the size of the set is less than the size of the array, return true. Else, return false.