class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();

        if(s.size() != t.size()) return false;

        unordered_map<char, int> mpp;

        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }

        for(char it : t){
            if(mpp.find(it) == mpp.end() || mpp[it] == 0) return false;
            mpp[it]--;
        }

        return true;    
    }
};

//Basically there are two strings. I need to check if the first string rearranged is the same string as the second one. 

//First approach that comes to my mind is to put the count of each letter in both the strings in a hashmap, and then compare the occurence of each letter in the first and second string. if at any point they're not equal then it's not an anagram, else it is.

//Approach A: If the length is different then it's definitely not an anagram. Then the usual hashmap approach for string 1, then iterate through string 2 and subtract the values from string 1. If it is not found or already 0 then it means it's not an anagram else it is. 

//Approach B: Using ASCII valus. This is to mainly improve space complexity to O(1). Create a vector of size 26, then subtract 'a' from each letter in string 1 and store it as a hashmap in the vector. Then the same approach as first one, subtract t[i] - 'a' for each letter in string 2. If at point it's already 0 return false. Keep on decrementing. Finally return true.

//Approach C: WE can compare hashmaps. Basically maintain two hashmaps for both the strings. The finally return hashmap1 == hashmap2. One loop. All done. 

// https://leetcode.com/problems/valid-anagram/