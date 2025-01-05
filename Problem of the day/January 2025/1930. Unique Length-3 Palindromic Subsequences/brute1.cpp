class Solution {
public:

    void findSubsequences(set<string> &words, string s, string temp, int i) {
        if (temp.size() == 3) {
            words.insert(temp);
        }

        // Check if `i` is out of bounds
        if (i >= s.size()) return;

        // Include the current character
        temp += s[i];
        findSubsequences(words, s, temp, i + 1);

        // Exclude the current character
        temp.pop_back();
        findSubsequences(words, s, temp, i + 1);
    }



    int countPalindromicSubsequence(string s) {
        int n = s.size();
        set<string> words;
        string temp = "";
        int index = 0;
        findSubsequences(words, s, temp, index);

        //Now words has all the subsequences of length 3. Now I need to pass each one through a palindrome checker.
        //On second thought I know the length of the palindrome is 3.
        //So all I need to do is to check if the first word == last word. Dumbass.

        int count = 0;
        for(auto it: words){
            if(it[0] == it[2]) count++;
        }

        return count;
    }
};


//BRUTE FORCE
//Initial thinking is to generate all the subsequences of the string of length 3, then check if it is a palindrome
//and then return the count. 
//How do I generate all possible subsequences?
//Recursion is a good first choice. Take & Not Take principle.
//So do the recursion method and generate a vector of subsequences of length 3. 
//Do the palindrome check for each subsequence in the array. 
//Maintain a count.
//Finally return it. 