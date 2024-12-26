class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //Step 1: I need to find pivot
        int pivot = -1;     //Incase there's no pivot, there's no next greater combo, return the reversed one. 3,2,1 => 1,2,3
        for(int i = n-2; i >= 0; i--){
            if(nums[i+1] > nums[i]){
                pivot = i;
                break;
            }
        }

        //Step 2: Find the next greater element than pivot
        if(pivot == -1){
            reverse(nums.begin(), nums.end()); //Read line 6
        }else{
            for(int i = n - 1; i >= 0; i--){
                if(nums[i] > nums[pivot]){
                    swap(nums[i], nums[pivot]);
                    break;                          //Now I got {2,3,5,4,1,0,0}
                }
            }
            //Step 3: Sort the numbers to the right of the pivot
            sort(nums.begin() + pivot + 1, nums.end());
        }
    }
};

//HOLY GRAIL EXAMPLE  = {2,1,5,4,3,0,0}

//Step 1: I need to find the longest prefix first. Idk what that means, just watch the video again. 
//Step 2: To find the longest prefix, I need to find the first element that breaks the order. Like from the 
//end of the array it's coming like a peak, then I need to find the next element that breaks the peak. So
//with all those elements I can make bigger combos. So now you found the pivot point.
//Step 3: In the example, 1 is the pivot. Now you need to find the next element that is slightly greater than 2
//so that you can get the NEXT greater permutation. I mean you can get {2,5,1,2,4,0,0} or {2,4,1,3,0,0}. But
//I need the {2,3,5,4,1,0,0} (anthing after 3 doesnt matter for now) aka I need 3 after 2 to get the next greatest
//permutation. That is possible only by checking the next greatest element (greater than pivot) from behind since it
//is already ordered in ascending order. 
//Step 4: You found 3. Now swap it with the pivot. You get {2,3,5,4,1,0,0}. Now after 2,3 you need the smallest combo
//in order to TRULY get the next greatest permutation. I mean you already got the next one with 2,3. After that you 
//only need the smallest. So you can do this by simply sorting everything from the right of pivot.
//You get {2,3,0,0,1,4,5}.