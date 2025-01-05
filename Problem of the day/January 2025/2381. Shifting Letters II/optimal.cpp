class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int m = s.size();
        
        vector<int> prefixDiff(m + 1, 0);  // Changed to int to handle large numbers
        
        //Step 2; Traverse the array and populate the prefixDiff array according to the ranges
        for(auto it: shifts){
            int start = it[0];
            int end = it[1];
            int direction = it[2];

            if(direction){
                prefixDiff[start] += -1;
                prefixDiff[end + 1] += 1;
            }else{
                prefixDiff[start] += 1;
                prefixDiff[end + 1] += -1;
            }
        }
        
        // Calculate cumulative shifts
        int curr = 0;
        for(int i = m; i > 0; i--) {
            curr += prefixDiff[i];
            // Handle negative numbers properly
            int shifts = curr % 26;     //normal case, if curr is 27, 27%26 is 1, word has to be shifted one time.
            if(shifts < 0) shifts += 26;    //if it is negative, example -1, the shifts = -1%26 = -1. Add 26 to it, you get 25, which corresponds to the backward wrapping principle. 
            
            // Apply shift to current character
            int newChar = ((s[i-1] - 'a' + shifts) % 26);
            s[i-1] = 'a' + newChar;
        }
        
        return s;
    }
};

//Brute Force
//So all I need to do is shift each character in the range shifts[0] to shifts[1] by one, 
//Forward direction if shifts[2] = 1 
//Reverse direction if shifts[2] = 0
//TC = O(N^2).

//Optimal Method:
//The logic here is to perhaps come up with a way to get the total number of times I should shift each lettter as a whole
//instead of shifiting it each and every time. That's how we're using the concept of prefixsums over here. 
//Suppose for abc(first input) I need to do the shift in this way => [1,2,1]. i.e OP will be acd. start = 1, end = 2
//So what I can do it to create an array called prefixDiff of size n+1, and at index end + 1, I put 1.
//So prefixDiff[end+1] = 1 signfies every element before it has to be incremented by one. 
//But if you notice I only need to increment elements at indexes 1 & 2, not 0. So perhaps I need another index to decrement
//that +1. So if I put a -1 at index start, i.e prefixDiff[start] = -1, then by time we get to index 0(which is for 'a'), that -1
//decrements 1 to 0 (1 + (-1) = 0) and prefixDiff[start] will become 0. The final values in the prefixDiff array tell how many times we 
//need to move the characters forward or backward in 'abc'.
//If direction is forward, we need to put -1,1.
//If direction is backward we need to put it ulta, i.e 1,-1.
//This will also help for multiple shifts, just do a dry run with the first example, you'll understand.