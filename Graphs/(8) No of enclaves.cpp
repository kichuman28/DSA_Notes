class Solution {

private:

    void findDFS(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});


        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};

            for(int k = 0; k < 4; k++){
                int nRow = i + dRow[k];
                int nCol = j + dCol[k];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                    q.push({nRow,nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
    }


public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                findDFS(0, j, vis, grid);
            }

            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                findDFS(n-1, j, vis, grid);
            }
        }


        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                findDFS(i, 0, vis, grid);
            }

            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                findDFS(i, m-1, vis, grid);
            }
        }

        int count = 0;
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};


//Approach
//This problem is similar to surrounding regions.
//(1) First I need to traverse the boundaries of the matrix and wherever there is a 1 and it's not marked as visited in the visted matrix, I call a DFS function on that particular position.
//(2) So now in the visted matrix I know all the postions which are linked to the boundary. 
//(3) Now in the main function I do a traversal without considering the boundary. Then I check if each element is marked or not AND if it is a '1' in the grid matrix. If it's true it means these ones are not connected to the boundary. So I take a count of them and I return it.
// TC = O(n*m) on the possibility that all the elements are 1
// SC = 2 x O(n*m) for the visited matrix and the queue

// DFS code. For this you have to initalise drow and dcol outside or else it wont work

class Solution {

private:

    const int dRow[4] = {-1, 0, 1, 0};
    const int dCol[4] = {0, 1, 0, -1};

    void findDFS(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        // int dRow[] = {-1,0,1,0};
        // int dCol[] = {1,0,-1,0};

        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
            !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                findDFS(nRow, nCol, vis, grid);
            }
        }
    }


public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                findDFS(0, j, vis, grid);
            }

            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                findDFS(n-1, j, vis, grid);
            }
        }


        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                findDFS(i, 0, vis, grid);
            }

            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                findDFS(i, m-1, vis, grid);
            }
        }

        int count = 0;
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};


