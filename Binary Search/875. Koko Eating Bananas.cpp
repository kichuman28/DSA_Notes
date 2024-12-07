class Solution {
public:

    int findBananas(int num, int h, vector<int> &piles){
        long long hrs = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            hrs += ceil(double(piles[i])/num);
        }

        if(hrs <= h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //Step 1: Find the maximum element
        int maxi = piles[0];
        for(int i = 0; i < n; i++) maxi = max(maxi, piles[i]);


        //Step 2: Pass the value from 1 to maxi to a function which checks acc to the conditions. This is iterative search
        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = (low + high)/2;
            if(findBananas(mid, h, piles)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }


        //Step 3: Returning the answer.
        return low;
    }
};

//Algorithm
//BRUTE FORCE
//First I need to iteratively search from 1 till the maximum element in the arrray because after the max element in the array the time taken will be the same. 
//Then I need to pass each element iteratively from the range to another function which caluculates if it is possible to
//eat the bananas less than h. The first number which satisifies the condition is the minimum number of bananas koko needs
//eat per hour so that she will not feel so full and it is less than the number of hours (h) it takes for the guard to 
//reach back. 

//Optimal: Just use binary search to do the iterations