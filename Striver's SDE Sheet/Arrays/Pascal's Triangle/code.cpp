class Solution {
public:
//OPTIMAL APPROACH
    vector<int> findElement(int n, vector<int> &ans){
        vector<int> temp;
        temp.push_back(1);
        int res = 1;
        for(int i = 1; i < n; i++){
            res = res * (n - i);
            res = res / i;
            temp.push_back(res);
        }

        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> temp;
        for(int i = 1; i <= n; i++){ //It should start from 1 as we are giving the row number. There's no value for zero.
            vector<int> ans;
            temp.push_back(findElement(i, ans));
        }
        return temp;
    }
};


//Approach(Brute Force)
// There are three ways in which this question can be asked.
//(i) Find the specific element at the specified row and specified column
//(ii) Return the row containing the elements.
//(iii) Print the whole Pascal's triangle. 

//(i) Finding the specific element
// We find each element of a pascal's triangle using combination formula i.e nCr = n!/(n - r)! x r!.
// But we should not use factorial formula too find the answer because the TC will be too much.
// There's a shortcut. If n is the number of rows and r is the number of columns, you see that 10C3 = 10x9x8/3x2x1.
// i.e you just need the first 3 numbers from 10!. We get this info from the column number. 
// So just run a loop for the column number(i) and subtract i from the row number.
// Next divide the above step with the column number. Repeat this until the col loop ends.

//(ii) Printing a specific row.
// Just use the above formula for a specific row and return the row.

//(iii) Printing the whole triangle.
// We can use the same formula above for printing the whole triangle.
// We need two loops, one for the number of rows(i) and the second one for the number of elements(i+1).
// Use the same formula. But TC would be too much for this method. 
//TC = O(n*n*r), r is the number of columns, n is the number of rows.

//It's difficult to explain the concept here, so just watch the video for that. 
//You don't need to look at the first and last elements, they're always 1.
//The formula is this : ans = (row - col)/col
//Put that in a loop running from 0 -> col and you get the answer for each element. 
// TC = O(N) N : number of columns
// SC = O(1)

// class Solution {
// public:
// //BRUTE FORCE APPROACH
//     int findElement(int n, int r){
//         int ans = 1;
//         for(int i = 0; i < r; i++){
//             ans = ans * (n - i);
//             ans = ans / (i + 1);
//         }

//         return ans;
//     }

//     vector<vector<int>> generate(int numRows) {
//         int n = numRows;
//         vector<vector<int>> temp;
//         for(int i = 0; i < n; i++){
//             vector<int> ans;
//             for(int j = 0; j < i + 1; j++){
//                 ans.push_back(findElement(i, j));
//             }
//         temp.push_back(ans);
//         }
//         return temp;
//     }
// };