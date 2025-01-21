//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int count = 0;
        for(int i = 1; i <= n; i++){
            int m = i;
            while(m > 1){
                count += (m & 1);
                m = m >> 1;
            }
            if(m == 1) count += 1;
        }

        
        return count;
    }
};


//Brute Force: While I'm converting the binary to decimal keep track of the ones and return it.
//Better: Instead of using mod operator to check whether a number is odd or not, I can just
//do AND operation with 1 and check if it is 0 or not. For odd numbers doing AND operation 
//with 1 is always going to give zero, for even numbers it is going to give one. and instead of 
//dividing by two I can just right shift n by 1 since it does the same thing.