class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxi = 0;
        set<char> stt;
        for(int right = 0; right < n; right++){
            while(stt.find(s[right]) != stt.end()){
                stt.erase(s[left]);
                left++;
            }

            stt.insert(s[right]);
            int len = stt.size();
            maxi = max(maxi, len);
        }

        return maxi;
    }
};


//BRUTE FORCE
//Make all substrings, check if there are repeating characters by just using a simple hashmap, if none then take count,
//Calculate the maximum and return the count.
//TC = O(N^2)

//OPTIMAL : Sliding Window
//What we do is we maintain a left and right pointer. Both at 0. We move the right pointer till the end of string.
//Keep on adding s[right] to a hashset. The moment you find a duplicate character, remove from the beginning (s[left])
//until the duplicate character is removed from the set. Also keep track of the length as well.
//First we check for duplicate, then we add s[right] to the hashset. 
//TC = O(N).