//OPTIMAL METHOD (2 POINTER APPROACH)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = (n + m) - 1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){      //i >= 0 => we can only check elements of i until it gets over. So if that's done then there's no more reason to continue, just fill in the rest with the elements from nums2.
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                nums1[k]=  nums2[j];
                k--;
                j--;
            }
        }
    }
};

// Intuition
//What we are doing here is that we compare all elements of nums2 with nums1 and replace the elements of 0
//with the bigger among nums1 and nums2. So we need 3 pointers i, j, and k where i is for nums1(m), 
//j is for nums2(n) and k is for nums(n+m).
//Start from the behind and keep on checking and replacing until the nums2 gets exhausted. 