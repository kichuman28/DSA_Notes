class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int count = 0;
        set<string> stt;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    string str = "";
                    str = string(1, s[i]) + string(1, s[j]) + string(1, s[k]);

                    if(s[i] == s[k]){
                        stt.insert(str);
                    }
                }
            }
        }

        return stt.size();
    }
};


//BRUTE FORCE
//Initial thinking is to generate all the subsequences of the string of length 3, then check if it is a palindrome
//and then return the count. 
//How do I generate all possible subsequences?
//Recursion is a good first choice. Take & Not Take principle.
//So do the recursion method and generate a set, not vector of subsequences of length 3. 
//The reason we are using a set is that we need unique subsequences, so the set categorizes them.
//Do the palindrome check for each subsequence in the array. 
//Maintain a count.
//Finally return it. 
//TC = 2^n.