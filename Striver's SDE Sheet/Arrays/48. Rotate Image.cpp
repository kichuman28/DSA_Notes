class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n, 0));  

        //Step 1: Find the transpose of the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i < j)swap(matrix[i][j], matrix[j][i]); //We need this condition to make sure that we don't swap the same element twice, which literally gives us the same matrix.
            }
        }


        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//Brute Force: 
//Just look at the patterns and come up with a technique. But that is not in place. 
//For that you need to byheart the solution. 


//Optimal Method:
//Step 1: Find the transpose of the matrix
//Step 2: Then reverse each row.