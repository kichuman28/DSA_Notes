class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = (n*m) - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int element = matrix[mid / m][mid % m];
            if(target == element){
                return true;
            }else if(target < element){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return false;
    }   
};

//Brute force
//Just do a normal linear search through the matrix. 
//This gives us a time complexity of O(n^2).

//Optimal Method:
//Flatten the matrix into a 1 d array hypothetically. 
//Now we can perform binary search on it since everything is in sorted order.
//But the question is how to convert the mid into it's specific row and col number.
//row = mid / col0
//col = mid % col0
//Why we are dividing by col number? It's more like an offset, circular array example. 
//In the second, testcase, there are 3 rows and 4 columns. We know each row contains 4 elements, aka the number of columns.
//So to find the column number of maybe the 5th element all we have to do is divide it by 4 to get it's actual col number.
//Common sense and observation.
//Col number is pure observation skill, you'll notice that the remainders give out the exact col number needed.