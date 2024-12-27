class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int ptr = 0;

        while(ptr <= right){
            if(nums[ptr] == 2){
                swap(nums[ptr], nums[right]);
                right--;
            }else if(nums[ptr] == 0){
                swap(nums[ptr], nums[left]);
                left++;
                ptr++;
            }else{
                ptr++;
            }
        }
    }
};

//Optimal Method: Dutch National Flag algorithm
//Step 1: Maintain 3 pointers. leftPointer, rightPointer and iterator. 
//Step 2: leftPointer starts from the beginning, rightPointer starts from the end and iterator is for moving.
//Step 3: The main aim to to move all 2's the end and 0's to the begininng. 
//Step 4: So if the iterator comes across 2, swap it to the value in the rightPointer and decrement rightPointer by one. Do not increment ptr here as the swapped value from the right has not been processed yet, it can be 0,1,2.
//Step 5: If the iterator comes across 0, swap it to the value in the leftPointer and increment leftPointer by one. Also increment the iterator. Here we can increment ptr coz the left value will always contain zero.
//Step 6: If the iterator comes across 1, just increment the iterator.
//Step 7: Continue doing this until the iterator is <= rightPointer. 