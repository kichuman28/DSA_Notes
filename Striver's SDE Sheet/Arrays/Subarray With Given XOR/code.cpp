//OPTIMAL METHOD
#include<bits/stdc++.h>
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    int xr = 0;
    int count = 0;
    map<int, int> mpp;
    
    mpp[0] = 1;//This is the same as adding mpp[0] = 1 in the OG problem. Suppose in one of the subarray we get the sum = B. So sum ^ B => sum ^ sum = 0. So we need to somehow notify that if we get 0 as the xor operation, the subarray with xor = B is present once. We cannot do it inside the for loop, as we are only inserting elements in the array to the hashmap. So we need to manually add '0' with a count of '1' in the map.
    
    for(int i = 0; i < n; i++){
        xr ^= A[i];
        int rev = xr ^ B;       //Similar to sum - B.
        if(mpp.find(rev) != mpp.end()){
            count += mpp[rev];
        }
        
        mpp[xr]++;      //For future references, similar to old problems. 
    }
    
    return count;
}


//Brute Force
//Use two for loops, find all possible sub array with xor as B, maintain a count and return it.
//TC = O(N^2)

//OPTIMAL
//This is the exact same problem as Count Subarray Equal K. Except here intead of addition we have xor.
//So how does the concept work using hashmap? We find the xor till a particular subarray.
//In order to find the subarray inbetween with an xor of B, we can subtract the current sum - B.
//If that sum - B exists in the hashmap, then we can increment the count with mpp[sum - B].
//But this ain't addition. This is XOR operation. So I need to find the equivalent of 
//sum - B. Don't worry, here it's just sum ^ B. 
//There's a derivation behind it. Refer the image.
//That's it. We found the answer. 
