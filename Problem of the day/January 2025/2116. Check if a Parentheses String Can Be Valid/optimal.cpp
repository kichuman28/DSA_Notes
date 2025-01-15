class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        stack<int> lock;
        stack<int> unlock;

        if(n % 2 != 0) return false;

        for(int i = 0; i < n; i++){
            if(locked[i] == '0'){
                unlock.push(i);
            }else{
                if(s[i] == '(') lock.push(i);
                else{
                    if(!lock.empty()){
                        lock.pop();
                    }else if(!unlock.empty()){
                        unlock.pop();
                    }else{
                        return false;   //Both the stacks are empty & the char is locked '('
                    }
                }
            }
        }


        while(!lock.empty() && !unlock.empty()){
            if(lock.top() > unlock.top()){
                return false;
            }
            lock.pop();
            unlock.pop();
        }


        return lock.empty();
    }
};


//Approach
//I can do this problem with some concepts from valid paranthesis. 
//For open brackets ')' with l = 1, I can't do anything. So I need to check either for closing brackets '(' or open brackets
//')' with l = '0' so I can change it to '('. 
//So if I encounter '(', I add it to stack regardless if it's l = 1 or 0. If it is ')' add it to stack if l = '0'.
//In this way I can make valid combos. But the problem with this is that in testcase 1, after making the first 4 char as 
//valid sets, I'll still have '((' in my stack due to logic from the last two char.
//Here it's pure observational skills. If the number of closing brackets with l = 0 is even, I can make valid pairs.
//If not I can't make it. So in the end I just have to check if the number is odd or not to return true or false. 

//Why does this method fail?
//What if the remaining brackets in the stack are locked ones? Even if they are even? Like two '(' with l = 1? Can I make them
//valid? Nope. Because I am using the same stack for both locked and unlocked parenthesis.


//Even with this code, the issue is that for testcase '))()))' with locked = '010111', the last two brackets remain in the 
//the lock array. Instead of using my fucked up code, I can do the following changes

//Instead of pushing brackets into the stacks which has no use at all, I can push the indices of the brackets. How this helps
//us is that at the end if there are brackets in both lock and unlock stacks, I can compare the indices at lock.top() and 
//unlock.top(). 
//If the index at lock.top() is greater than unlock.top() it means that I cannot make it valid. lock only contains stictly
//'(', so if a wild card appears before it then it doenst matter, we return false. 
//Other than that, if there are brackets left in both lock and unlock we keep on popping them as each one complements the
//other. 
//At the end if there are still brackets in locked, we return false, else we return true. Because any number of brackets in
//lock stack, either odd or even can't help because we can't form valid pairs with it. 
//Even if the unlock stack has brackets, it's always going to be even becuase we are checking in the beginning if the string's
//size is even or not. If it's odd we return false.