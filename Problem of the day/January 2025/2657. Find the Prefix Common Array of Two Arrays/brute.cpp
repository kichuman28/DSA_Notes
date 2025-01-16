class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);    
        map<int, int> mpp;

        for(int i = 0; i < n; i++){
            mpp[A[i]]++;
            mpp[B[i]]++;

            int count = 0;
            for(auto it: mpp){
                if(it.second >= 2) count++;
            }

            ans[i] = count;
        }

        return ans;
    }
};


//Approach
//Logic is simple, all we have to do is find out if the occurence of each char in both A & B at a particular index is 2 or not
//If it is 2, it means both characters are there in A & B till this particular index, I can get the count of how many such
//characters are there and store in the prefix array.
//Finally return the array
//TC = O(N^2)


// Optimal
//I can just use a hashmap and caculate the freq till index i. If the index is is 2 I can increment the common count by 1. 
//Then add it to the ans array. 
//TC = O(N)