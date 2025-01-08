class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int count = 0;
        
        for(int i = 0; i < n; i++){
            int count = 0;

            //Check in forward direction
            for(int j = i+1; j < n; j++){
                if(boxes[j] == '1'){
                    count += (j - i);
                }
            }

            //Check in backward direction
            for(int k = 0; k < i; k++){
                if(boxes[k] == '1'){
                    count += (i - k);
                }          
            }
            
            ans[i] = count;

        }
        return ans;
    }
};

//BRUTE FORCE
//I need to maintain an array of size n+1, 0 to store the answers.
//From a particular index, I check both forward and backward whether a ball is present or not.
//If yes from forward I subtract j - i to get the no. of positions to shift the ball backward.
//If yes from backward I subtract i - k  to het the no. positions to shfit the ball forward.
//Then set the shifts to the position on the boxes array. 
//return the array.
//TC = O(N^2)