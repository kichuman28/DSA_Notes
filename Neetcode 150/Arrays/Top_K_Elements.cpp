class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<vector<int>> buckets(n+1);
        vector<int> ans;

        for(auto it : nums){
            mpp[it]++;
        }

        for(auto it : mpp){
            buckets[it.second].push_back(it.first);
        }

        int count = 0;
        for(int j = n; j >= 0; j--){
            for(auto it : buckets[j]){
                ans.push_back(it);
                count++;
                if(count == k) break;
            }
            if(count == k) break;
        }


        return ans;
        
    }
};


//Approach A: Basically the problem states that I have to find the numbers which occurs less than or equal to (at most) the target number and return it in an array. This is easy, I can use a hash map to store the occurence of each element, then iterate through the hash map to see if it's greater than or equal to the count, if yes then add it to an array and return it. 

//Big nono. Turns out I have to find out which all elements are repeating the most. That count is being defined by 'k'. That is if 1 occurs 3 times, 2 occurs 4 times and 3 occurs 8 times, the order according to how many times they occur is 3 > 2 > 1. If k = 2, then I have to return 3 and 2. New thing learned today is custom comparator for sort function. I can't use a map because it's iterators don't allow me to access the value and sort it accordingly. So I need to use a vector<pair<int, int>> to add the pairs from the map to this. Then I use a custom sort function. The sort function has a 3rd parameter where can add add a lambda function which starts with '[]', give the arguments which I am comparing, it this case two pairs. Then sort them with the logic that if one of the pair's second is greater than the other it should come first. Then from that sorted vector of pairs, return the top k ones. TC = O(n log n) due to sorting. I need it in O(n)

//Approach B(Optimized one)

//The number of times an element occurs maximum will be the size of the list, not more than that. For example consider this array = [1,1,1,1,1]. The freq of 1 will be max 5, which is the size of the array (n). Similarly for array = [1,1,2,3,2,2,,4,4,2], max freq of 4 is 2 in this case, but it can go upto 9 (size of the array n) but not more than that. So if I can categorize it according to buckets of freq, I just need to calcualte the freq of each element, attach that to the correct freq bucket which will already be sorted since we are using vector<vector<int>> buckets(n+1) where the index is the max freq and the element is the actual element in nums. The reason why we are using vector of vectors and not just a single vector is because if there are multiple elements in nums with the same freq, I can't attach multiple numbers to a single index in buckets if I am using only vector. Hence vector of vectors. Example is below. [1,1,2,2,2,3,3,3,5,5,5,5] . After gettig the bucket just iterate from behind till k and return it. O(n).

// bucket[0]  → []
// bucket[1]  → []
// bucket[2]  → [1]
// bucket[3]  → [2, 3]
// bucket[4]  → [5]
// bucket[5]  → []
// ...
// bucket[12] → []

// https://leetcode.com/problems/top-k-frequent-elements/