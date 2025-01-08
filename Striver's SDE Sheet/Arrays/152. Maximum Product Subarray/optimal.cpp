class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int leftProduct = 1;
        int rightProduct = 1;
        for(int i = 0; i < n; i++){
            
            if(leftProduct == 0) leftProduct = 1;
            if(rightProduct == 0) rightProduct = 1;
            
            leftProduct *= nums[i];
            rightProduct *= nums[n-i-1];

            maxi = max(maxi, max(leftProduct, rightProduct));
        }

        return maxi;
    }
};

//Brute Force
//Use two for loops, consider all subrarray's products, find the maxi, return it.
//TC = O(N^2).

//Optimal
//This is purely observational.
//First thing we notice is that if the array contains only positive numbers then the product 
//of the entire subarrray is the answer.
//Next is the possibility of negative integers.
//If there are odd number of negative integers then we'll get a negative answer,
//If there are even number of negative integers we'll get a positive answer.
//if we take arr = [2,3,-2,8] as example, if we start from index 0 and calculate the subarrays
//the answer is [2,6,-12,-96]. Maxi is 6. Thing is if I started from behind, I'd get the ans
//as [-96,-48,-16,8]. Now the maxi is 8. 
//So for this reason, if I keep on calculating the maxi from end and start I can get the ans.
//Only edge case is when a 0 occurs. When a 0 occurs you don't have to carry that forward.
//So if a 0 is encountered then convert the product = 1 so that as you move forward, we
//again start a new subarray. 
//TC = O(N) 