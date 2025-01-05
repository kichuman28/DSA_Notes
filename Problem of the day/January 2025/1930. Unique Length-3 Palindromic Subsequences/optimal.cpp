class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int count = 0;
        //Step 1: We need a hashmap with the frequencies
        map<char, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }

        set<string> result;    
        set<char> stt;
        //Step 2: Traverse the array, check if it is a palindrome, increment the count, return it.
        for(int i = 0; i < n; i++){
            mpp[s[i]]--;            //left half

            for(auto it: stt){
                if(mpp[it] > 0){            //We can't use mpp.find() because even if the freq is 0, the key will still be present in the map.
                    string str = "";
                    str = string(1, it) + string(1, s[i]);
                    result.insert(str);
                }
            }
            stt.insert(s[i]);       //right half
        }

        return result.size();
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

//OPTIMAL WAY
//Instead of using two sets and putting elements in them each and every time, maybe I can do it in one iteration.
//First put all elements and their frequency inside a hashmap.
//Then use a set while traversing the array
//For each element you encounter, subtract it's freq from the hashmap and add it to the set. 
//The element we encounter is the middle element, the element in the set is the first elemenet, the element in the hashmap
//is the third element.
//So we check is every element in the set(rightside) is present in the hashmap(leftside) or not. If yes then it means
//a palindrome can be formed. If it doesn't then not a palindrome. Maintain a count, return it.
//So now we don't have to add to a set everytime, we add everything to the map first and as we traverse the array each time,
//we put elements into the left and right side automatically. 
//TC = O(N) 