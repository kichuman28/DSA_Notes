class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int slow1 = 0;
        int ans;
        while(true){
            slow1 = nums[slow1];
            slow = nums[slow];
            if(slow == slow1){
                ans = slow;
                break;
            } 
        }

        return ans;
    }
};

//Approach
//In order to solve this problem using constant space I need to use Floyd's Hare & Tortoise algorithm to find the repeated number.
//So if you see the nums array, you'll see that when you try to form a linked list with the index as pointers, at some
//point you'll come across a cycle. This will always be true for this question. 
//We need to return the node where the cycle starts. 
//Maintain two pointers, slow and fast from the beginning of the array. Move slow by one and fast by 2.
//The moment slow becomes equal to fast, you break. 
//Now we need to set another slow pointer at the beginning of the array, and move it so that the first slow pointer 
//and the second slow pointer meet each other. The point where they meet is the repeated number.
//Just watch NeetCode's video for indepth intuition understanding of the problem.