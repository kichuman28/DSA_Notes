class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mpp;

        for(auto it: strs){
            string word = it;
            sort(word.begin(), word.end());
            mpp[word].push_back(it);
        }

        vector<vector<string>> ans;

        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};


//I definetely need an anagram checking function with two parameters. I check check each word from the list via a nested for loop (skipping the current work which is being checked). After that I can add that vector to a set after sorting to get the unique list instead of going through each word in the given list. Then add the vector of strings from the set into a vector of vector of strings and return it. TC = O(N^2). TLE.

//You can create a map of <string, vector<string>>. Then iterate though each word. First sort the word. Then keep the sorted word as the key and add all the anagrams as vector of strings of that key. You can push_back strings to a vector of string that acts as a value to a key.. Finally extract the values from the map to a vector of vector of strings and return it. TC = O(N) 

// https://leetcode.com/problems/group-anagrams/