vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long sumNatural = (n*(n+1))/2;
    long long sumSquare = (n*(2*n+1)*(n+1))/6;
    
    long long arraySum = 0;
    long long sqaureArraySum = 0;
    for(int i = 0; i < n; i++){
        arraySum += A[i];
        sqaureArraySum += (A[i] * A[i]);
    }
    
    long long X;  //repeatedNumber
    
    long long Z = sumNatural - arraySum;
    // X - Y = Z;
    long long U = sumSquare - sqaureArraySum;
    // X + Y = (Z/U);
    X = (U / Z + Z)/ 2;
    long long Y = X - Z;
    
    return {Y, X};
    
}

//Brute Force
//Maintain a frequency map. 
//Add the keys. 
//Add them. Subtract it from the sum of 'n' natural nummbers formula.
//You got the missing number. 
//Next take a note of the number whose frequency is 2. That's the repeatedNumber.
//Return it in {repeatedNumber, missingNumber} format.


//Optimal one
//Same concept. I do subtraction from sum of n natural number and the sum of the given array
//The answer will give us X - Y = Z, where X is the repeatedNumber and Y is the missingNumber.
//But we have no idea which one is which, so we need to solve the equation to get the values of X & Y.
//So to solve this I need another equation, which I'll obtain by Subtracting the square of the numbers 
//of the given array from the sum of square of first N natural numbers.
//I'll get X^2 - Y^2 = U. I know X^2 - Y^2 is (X + Y)*(X - Y). I know the value of X - Y from above.
//So substituting, I get X + Y = U/Z, where Z => X - Y. 
//Now solve the 2 equations, you get the answer.