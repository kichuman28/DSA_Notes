class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefixSum(n, 0);

        int balls = 0;
        int moves = 0;

        //Forward direction
        for(int i = 0; i < n; i++){
            prefixSum[i] = balls + moves;

            moves = balls + moves;//You can put balls = prefixSum[i], but it will fuck things up when we are calculating the moves in the reverse direction. So you need to again give balls + moves.
            if(boxes[i] == '1') balls++;//We should only update the balls after the move is set

        }

        balls = 0;
        moves = 0;

        for(int i = n-1; i >=0 ; i--){
            prefixSum[i] += balls + moves;

            moves = balls + moves;      
            if(boxes[i] == '1') balls++;
        }

        return prefixSum;
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

//Optimal (Prefix sum modification)
//This whole concept goes behind the number of balls and the number of moves it takes to 
//reach a certain position.
//Intuition is we calculate how much moves it took for all the balls to move to a certain index
//Next we also track the no. of balls. So to calculate the no. of positions moved for the next
//stage will be the no. of moves till the previous index + the no. of balls needed to move to
//the next stage. So balls + moves. The no of balls increases depending on whether boxes[i] = 1
//or not.
//Do this for both forward and reverse direction because we need to know from both the 
//directions. At the end we will get a prefixSum array with the required answer.
//TC = O(N)