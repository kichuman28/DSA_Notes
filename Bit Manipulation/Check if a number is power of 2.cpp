//So for brute force I can just convert a number to binary and count the number of ones.
//If it has only 1 number of ones then it is a power of 2. Else it is not.
//Try with examples 32 & 13.
//Optimal route, if you notice that on doing an AND operation on 32 & 31, we get zero.
//AND operation on 13 and 12 does not give zero.
//This is true for all numbers which are a power of 2.
//For number 'N' which is a power of 2, doing N & N-1 will give 0, for others it will not. 

class Solution{
    public:
        bool checkPower(int num){
            if(num && (num-1) == 0) return true;
            return false;
        }
};