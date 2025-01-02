class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();

        vector<int> ans;

        //I need a set to store the vowels
        unordered_set<char> vowels = {'a','e','i','o','u'};

        //Use two for loops.
        //One for traversing the queries and checking each range
        //Second one for checkig which all words in the range start with a vowel.

        for(int i = 0; i < m; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int count = 0;
            for(int j = start; j <= end; j++){
                int len = words[j].size();
                char first = words[j][0];
                char end = words[j][len-1];
                if(vowels.find(first) != vowels.end() && vowels.find(end) != vowels.end()) count++;
            }
            ans.push_back(count);
        }

        return ans;
    }
};
//This approach is brute force. TC at max = O(N^2).



//Question:
//Queries consist of the range in words from which I should get the count of the words that start with a vowel. 
