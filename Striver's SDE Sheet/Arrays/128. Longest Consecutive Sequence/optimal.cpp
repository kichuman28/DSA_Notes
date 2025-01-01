class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()) return 0;
        //Step 1: Maintain a set
        set<int> stt(nums.begin(), nums.end());
        int maxi = 0;
        //Step 2: Traverse the array to find the beginning and to increment count
        for(auto it: stt){                         //Don't use array here you'll get TLE
            if(stt.find(it - 1) == stt.end()){     //Checking whether an element smaller than nums[i] is not there
                int count = 1;
                int num = it;
                while(stt.find(num + 1) != stt.end()){
                    count++;
                    num++;
                }
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};


//Brute Force
//Sort the array
//maintain a count until the sequence breaks off
//return the count
//TC = O(NlogN) + O(N)

//Note: Multiple Sequences can be present. So each time a sequence breaks off we need to find the count of the 
//supposed new sequence.


//Optimal Method
//Maintain a hashset. 
//Insert all elements into it. 
//Traverse the array again and for every element arr[i], check if arr[i] - 1 exists or not.
//If it exists then it means there'a smaller element to start the sequence, we have have to continue searching.
//It it doesn't exist, then it means there's no smaller element than this one, so this is bound to be the start.
//From there check by adding one to the starting sequence and check if it's there in the set or not. Increment count & maintain maxi.
//If it's not there then a new sequence has started, maintain maxi to change the count
//TC = O(N)
