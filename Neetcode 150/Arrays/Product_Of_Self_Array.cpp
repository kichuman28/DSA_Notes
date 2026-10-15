class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);

        int start = 1;
        for(int i = 1; i < n; i++){
            answer[i] = nums[i-1] * start;
            start = answer[i];
        }

        int end = 1;
        for(int i = n-2; i >=0 ; i--){
            answer[i] = answer[i] * (nums[i+1] * end);
            end = nums[i+1] * end;
        }

        return answer;
    }
};




//Brute force logic is to just loop over the array and fill the second array with the product of all the elements except the current chosen one. 

//Optimal one is to undertand that there's a left side and right side to every element I need to calculate. Consider these two prefix and suffix arrays : [1,1,2,6] & [24,12,4,1]. So at each position for the answer array, I have the numbers I need to multiply inorder to get the answer I need. So now I don't need to multiply them each and everytime in order to get answer[i]. I can just find the prefix and suffix answers of the given array and for a particular element for answer[i] I can just multiply prefix[i] & suffix[i], which already contains all the numbers from left to right calculated and right to left caculated from i.

//https://leetcode.com/problems/product-of-array-except-self/