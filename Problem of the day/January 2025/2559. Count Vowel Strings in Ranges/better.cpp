class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();

        vector<int> ans;

        unordered_set<char> vowels = {'a','e','i','o','u'};
    
        //I need an array to store the valid words till an index
        vector<int> prefixSum(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            string str = words[i];
            int len = str.size();
            int first = str[0];
            int last = str[len-1];
            if(vowels.find(first) != vowels.end() && vowels.find(last) != vowels.end()){
                sum++;
            }
            prefixSum[i] = sum;
        }

        //Now I have to iterate queries and get the count for each range from the prefix sum.
        for(auto it: queries){
            int start = it[0];
            int end = it[1];
            
            if(start == 0){
                ans.push_back(prefixSum[end]);      //Because if the starting range is zero then I just have to return all
                                                    //the strings till the end index in the prefixSum array.
            }else{
                int count = prefixSum[end] - prefixSum[start - 1];
                ans.push_back(count);
            }
        }

        return ans;

    }
};
//This approach is brute force. TC at max = O(N^2).



//Question:
//Queries consist of the range in words from which I should get the count of the words that start with a vowel. 


//Optimal Approach
//Precompute if each string is valid or not so that each and every time I don't have to brute force it and check every time.
//Like for words = ["aba","bcb","ece","aa","e"], I can create an array which shows the valid strings till an index by using
//'1' for valid word and '0' for invalid word. So the array will look like [1,1,2,3,4].
// When query ranges are given in question, usually the go to approaches are

// Prefix Sum
// Binary Search
// DP
// Here, we can pre-compute the valid / invalid strings by marking them as 1 and 0
// valid - 1
// invalid - 0

// Now instead of brute-force counting every valid string, how about marking the number of valid strings till a particular index?

// Ex -

// ["bcb","aba",'xzx','yzy',"ece"] 
// [  0  ,  1  ,  0  ,  0  ,  1  ]  -- valid strings
// [  0  ,  1  ,  1  ,  1  ,  2  ]  -- valid strings till an index (prefix sum array)
//          ^                 ^
// Now for the query [1,4]

// We can simply use the pre-computed array to process the answer
// index[4] - index[0] = 2 - 0 => 2 valid strings

// So whenever pre-computation is helpful, think of prefix sum.
// Hope this helps :)