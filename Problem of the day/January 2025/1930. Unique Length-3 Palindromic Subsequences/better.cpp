class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int count = 0;
        set<string> stt;
        for(int i = 1; i < n-1; i++){
            set<char> leftHalf;
            set<char> rightHalf;

            for(int j = 0; j < i; j++) leftHalf.insert(s[j]);
            for(int k = i+1; k < n; k++) rightHalf.insert(s[k]);

            for(auto it: leftHalf){
                if(rightHalf.find(it) != rightHalf.end()){
                    string str = string(1,it) + string(1,s[i]) + string(1,it);
                    stt.insert(str);
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

//BRUTE FORCE 2
//use three for loops since the subsequence is only of length 3. 
//Check if s[i] & s[k] are equal for palindrome. 
//Add them to set so that the O/P only contains unique answers.
//Return the size of the count.
//TC = O(N^3)

//BETTER WAY
//I can perhaps take one of the element as the middle element, then check if each element from the left side is present in
//the right side or not. I can use a set for storing both the left & right halfs and use them to search in O(1) TC.
//If yes then I can make a 3 length palindrome with that, increment the count
//Finally return it.
//TC = O(N^2). 