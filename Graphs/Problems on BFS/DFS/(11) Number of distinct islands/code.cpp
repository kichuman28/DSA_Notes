class Solution {
  public:
  
    void findDFS(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &temp, int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        temp.push_back({row - row0, col - col0});
        
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        
        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
            && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                findDFS(nRow, nCol, vis, grid, temp, row0, col0);
            }
        }
    }
  
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> stt;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int, int>> temp;
                    findDFS(i, j, vis, grid, temp, i, j);
                    stt.insert(temp);
                }
            }
        }
        
        return stt.size();
    }
};


//Approach
//This is basically an extension of the number of islands problem. We just need the
//number of distintly shaped islands (refer photo/video). So the question is how to 
//undertand the shape. This is where the concept of base cordinate comes in. Refer the
//photo again. If there are two similar islands then each cordinate of that island subtracted
//from the base point will be the same. So if you add those vector of coordinates(each vector
// of cooridnates represents an island) to a set, it'll only include the islands which
//consists of unique islands. So in the end you just return the size of the set and
//boom you get the answer.

//Psuedo Code
//The same structure for number of islands problem. 
//First we traverse the matrix to see the starting points aka base coordinates of islands
//If we find one and it is not visited, we do DFS traversal on it and also pass the vector
//of pair aka temp and the base coordinates(row0, col0) which remains constant for THAT
//DFS traversal. We have to initialise temp inside the for loop because it needs to reset for
//each new island. Then after the DFS traversal is done we add it to the set. 
//Finally we return the size of the set. 

//The DFS function is pretty much the same thing, we just have to insert {row-row0}, col-col0
//inside the temp every time. 

//TC = O(NxM) * 4 (DFS function) + O(NxM) for the loop in main function + log(set length) for insert function.
//SC = We're using a set, and two vectors approx O(NxM).