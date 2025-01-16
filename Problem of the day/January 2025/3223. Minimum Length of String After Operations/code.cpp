class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        map<char, int> mpp;

        for(auto it: s) mpp[it]++;

        int ans = 0;
        for(auto it: mpp){
            if(it.second >= 3){
                if(it.second % 2 == 0) ans += 2;    //For even freq
                else ans += 1;                      //for odd freq
            }else{
                ans +=  it.second;
            }
        }

        return ans;
 
    }
};

//Approach
//First thing is to find the character which has it's occurences on the left & right side. How do I do this?
//Brute force would be using a loop till each index, one from the beginning and another one from the end. 
//First time I find one from both sides, I'll do all the operations, 
//If I don't find one from any one side, then I return the length of the string, as in case 2.

//Okay I got the left & right index. Now the problem is removing them and using the same string again for further operations.
//I don't see any ways to do it linearly. Probably might have to use recursion.

//Recursion use. 
//Well the base case can be when I don't find a left or right index. I can return the length of the string. 

//Fuck all this. It's hashing
//Basically inorder to do all the operations according to the constraints given by the qs, I need atleast 3 occurences of 
//the character. After deleting the first occurences atmost 2 freq of the char must be there. It can be 2 or less after
//removing. 
//So I can just use a hashmap to get the freq of each element.
//Check if the freq is greater than 3. If yes I keep on subtracting 2(left & right occurence) until the freq is <= 2. 
//Next I just add the freq of all the elements and return it as answer.

//Welp that doesnt work as well. I can do another simple thing. 
//First I need to check whether the freq is >= 3. Done.
//Next I need to reduce it until there are no 3 freq left. For even freq, example 4, I can reduce it till 2. 
//For odd freq, example 5, I can reduce it till 1 if I keep on subtracting 2 from it. 
//So I can just add the remaining freq and that's the answer.
//