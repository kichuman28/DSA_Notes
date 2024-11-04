class Solution {

private:
    void findDFS(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow >=0 && nRow < n && nCol >= 0 && nCol < m &&
            !vis[nRow][nCol] && board[nRow][nCol] == 'O'){
                findDFS(nRow, nCol, vis, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        //Checking the first and last row for 'O'
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                findDFS(0, j, vis, board);
            }

            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                findDFS(n - 1, j, vis, board);
            }
        }


        //Checking the first and last column for 'O'
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                findDFS(i, 0, vis, board);
            }

            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                findDFS(i, m - 1, vis, board);
            }
        }




        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                    vis[i][j] = 1; 
                }
            }
        }
    }
};


//Approach
//(1) Okay so if the boundaries has any zero and it is connected to some inner zero then that means that can't be surrounded. So we first we have to care of the boundary zeroes.
//(2) So first we check the boundaries for any zeroes. If it has any then we run a DFS from that position in the matrix. Maintain a visited array as well, mark the same places in vis as '1'. 
//(3) Now we have all zeroes and the corresponding indexes marked as 1 in the visted matrix.
//(4) Now we check the inner matrix. If any of the indexes are marked as 1 in the inner matrix when we did dfs from the boundaries then it means there's a path outside. Don't mark it as 'X'. Mark everything else as 'X'. 

//TC = O(NxM)
//SC = O(NxM) for vis aray