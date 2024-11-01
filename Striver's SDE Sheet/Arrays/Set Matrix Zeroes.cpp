//Optimal Approach
//(1) Use an additional row array and column array. Set all elements are zero. Mark them as 1 if you encounter a zero in the same array in the matrix. 
//(2) Then reiterate the matrix and wherever there is a one in the row array and column array mark that position as 0 in the given matrix.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }


        for(int i = 0;  i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};







//Brute Force Approach 
//(1) First traverse through the matrix and covert the rows and coloumns where you find a zero to -1. 
//(2) Then traverse the matrix again and convert the -1 to 0.
//(3) Problem with this apporach is I can't use any other integers like -1. So brute force? Yes. Optimal? no.

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(matrix[i][j] == 0){
//                     for(int k = 0; k < m; k++){
//                         if(k != j && matrix[i][k] != 0){
//                             matrix[i][k] = -93;
//                         }
//                     } 
//                     for(int k = 0; k < n; k++){
//                         if(k != i && matrix[k][j] != 0){
//                             matrix[k][j] = -93;
//                         }
//                     }
//                 }
//             }
//         }


//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(matrix[i][j] == -93) matrix[i][j] = 0;
//             }
//         }
//     }
// };




