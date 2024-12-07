class Solution {
public:

    int divideBalls(int num, int maxOperations, vector<int> &nums){
        long long ops = 0;
        for(int i = 0; i < nums.size(); i++){
            ops += ceil((double)nums[i]/num) - 1; 
        }
        if(ops <= maxOperations) return true;
        return false;
    }


    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();

        //Step 1: Find maximum range
        int maxi = nums[0];
        for(int i = 0; i < n; i++) maxi = max(maxi, nums[i]);

        // //Step 2: Do iterative search
        // int ans;
        // for(int i = 1; i <= maxi; i++){
        //     if(divideBalls(i, maxOperations, nums)){
        //         ans = i;
        //         break;
        //     }
        // }

        //Step 2: Do binary search
        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = (low + high)/2;
            if(divideBalls(mid, maxOperations, nums)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};

//Approach
//Here I need to find the number of balls per bag rate
//So I need to try out all the rates from 1 till the max size in nums array which will tell how many bags I can divide
//the max bag into. Why till max size? Because every ball per bag rate after max size will return me the same answer(koko)
//Like in example two, if the ball/bag rate is 8 then I can take all 8 balls in one bag. After 8 it's 9 which does the same thing. So just go till 8. 
//Brute force is iterative search from 1 till 8.
//Optimal is binary search from 1 till 8.