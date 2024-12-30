class Solution {
public:

    double pow(double x, long long n){
        if(n == 0) return 1;

        double res = pow(x, n/2);
        res = res * res;

        return n % 2 ? res * x : res;
    }

    double myPow(double x, int n) {
        long long num = n;
        double ans = pow(x, abs(num));
        if(n < 1) return 1/ans;
        return ans;
    }
};

//Brute Force:
//A for loop til n, multiply and return the answer.
//If n < 0, return 1/ans.

//Optimal (Recursion)
//We know 
//2^10 = 2^5 * 2^5
//2^5 = 2^2 * 2^2 * 2 (odd)
//2^2 = 2^1 * 2^1
//2^1 = 2^0 * 2^0 * 2. (odd)        We stop here.
//So instead of using a for loop to count that many iterations, we can use a single branch recursive solution
//to solve this problem. Keep on dividing n by 2 until the value reaches 0. 
//When you multiply by itself, you'll notice that for odd numbers we have to multiply the answer by one extra 'x'. 
//So just take care of that while returning the answer. That's it.
