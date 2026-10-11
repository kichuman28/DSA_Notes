class Solution {
public:
    string decodeString(string s) {
        int n = s.size();

        int count = 0;
        string currStr;
        stack<int> intStack;
        stack<string> strStack;

        for(int i = 0; i < n; i++){            
            if(isdigit(s[i])){
                
                count = count * 10 + (s[i] - '0');
            
            }else if(s[i] == '['){

                intStack.push(count);
                strStack.push(currStr);
                count = 0;
                currStr = "";
            
            }else if(s[i] == ']'){
            
                string combString;

                int num = intStack.top();
                intStack.pop();
                for(int i = 0; i < num; i++){
                    combString += currStr;
                }

                string prevStr = strStack.top();
                strStack.pop();
                currStr = prevStr + combString; 
            
            }else{
            
                currStr += s[i];
            
            }
        }

        return currStr;
    }
};



//This problem is easy if it's only single brackets. I can just use a for loop to check everytime I encounter '[' and multiply the character according to it and add it to another string. One pattern I know if that the bracket only comes after a number. 

//Okay for the second type of complex inputs, I need someway to remember the previous set of numbers and strings in order to add them to the inside ones. Remember that for this type of conditions, we need to use a stack due to it's LIFO structure. I need to remember both the number and string, so use two stacks here. There are primarily 4 types of data types I am going to encounter. A integer, an open bracket, a closed bracket and a letter. I need to figure out what needs to be done when each of them are encountered.


//https://leetcode.com/problems/decode-string/