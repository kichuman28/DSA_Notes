class Solution {
public:

    int mergeArray(int low, int mid, int high, vector<int> &nums){
        int left = low;
        int right = mid+1;
        vector<int> temp;
        int count = 0;
        int j = mid + 1;
        // Count reverse pairs using two-pointer technique
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2*(long)nums[j]) {
                j++;
            }
            count += (j - mid - 1);         //this is essentially j - (mid + 1)
        }


        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
        
        return count;
    }


    int mergeSort(int low, int high, vector<int> &nums){
        if(low == high) return 0;
        int mid = (low + high) / 2;
        int count = 0;
        count += mergeSort(low, mid, nums);
        count += mergeSort(mid+1, high, nums);
        count += mergeArray(low, mid, high, nums);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n-1, nums);
    }
};

//Brute Force
//Two for loops. Maintain the conditions and a count.
//Each time the condition is met, increment the count.
//Return the count.
//TC = O(n^2) & SC = O(1).

//Optimal
//So we try to apply the same logic in count inversions. We have two sorted arrays and we check if each element in left
//array is greater than 2 * nums[right]. If true, then it means all elements to the right of that element is greater.
//Same logic as we used in count inversions. BUT THIS WILL NOT WORK HERE.
//If one of the element in the left array does not satisfy the condition, then we skip everything else, this should not 
//be done as there might be other elements after it which can satisfy the condition. 
//So we do some changes in the two pointer approach.
//Now in the right side if the elements satisfy the condition for one of the element in the left array, then it means
//for the next element in the array the same elements will satisfy the condition. We try to leverage this.
//So the moment the condition is not satisfied in the right array, we stop.
//Then we take the count as right - (mid + 1). No need of an additional '+1' because right is stopped at an element which
//we do not need to take into consideration. That's it.

//Refer the images for more clarity.