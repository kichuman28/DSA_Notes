class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        //Traverse mat to search for starting points ('1') then mark it as visited in the vis matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){ //Here 0 is the starting point. I am the boss (I refers to = '0')
                    vis[i][j] = 1;
                    q.push({{i, j},0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            ans[row][col] = steps;

            int dRow[] = {-1,0,1,0};
            int dCol[] = {0,1,0,-1};

            for(int i = 0; i < 4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol]){ //I AM NOT COUNTING HOW FAR ANOTHER ZERO IS FROM ME, I AM ESTABLISHING THE DISTANCE FROM ME I.E '0' TO THE OTHER NODES IN THE 'ANS' MATRIX. ULTIMATELY THAT IS WHAT I AM RETURNING.
                    vis[nRow][nCol] = 1;//This is crucial step don't forget to mark it as visited
                    q.push({{nRow, nCol},steps + 1});
                }
            }
        }

        return ans;
    }
};


//Approach
//(1) This problem is similar to rotten oranges. You use BFS here to keep track of how many steps we took to get to the nearest '0'.
//(2) First we need to create a similar visited matrix of zeroes(unvisited).
//(3) For the queue we need the following parameters : {{row, col}, no. of steps to reach zero}.
//(4) First we need to insert the starting points into the queue, i.e the positions with '1'. Then mark them as visited in the visited matrix.
//(5) Next we iterate the queue until it is empty. Take out the first row, col and no. of steps, then pop it from queue.
//(6) If it is not visited then mark it as visited in the matrix. Also in the new matrix(which we have to return) mark that position with the 'no of steps' we got from the queue.
//(7) Next check all the four directions. First you should check if it is visited or not, then check if it is '0' or not. If both conditions are satisfied then push it into the queue, by updating the no. of steps by one(just add 1).
//Repeat this process and return the new array.

//TC = O(NxMx4) Visiting all the nodes as well as 4 for the del rows and cols.
//SC = O(NxM) for vis matrix.