// class Solution {
// public:

//     void findDFS(int node, vector<int> &vis, vector<int> adjLs[]){
//         vis[node] = 1;
//         for(auto it : adjLs[node]){
//             if(!vis[it]){
//                 findDFS(it, vis, adjLs);
//             }
//         }
//     }


//     int findCircleNum(vector<vector<int>>& adj) {
//         int n = adj.size();
//         vector<int> adjLs[n];
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(adj[i][j] == 1 && i != j){
//                     adjLs[i].push_back(j);
//                     adjLs[j].push_back(i);
//                 }
//             }
//         }
//         vector<int> vis(n, 0);
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             if(!vis[i]){
//                 count++;
//                 findDFS(i, vis, adjLs);
//             }
//         }

//         return count;
//     }
// };


///Code using BFS 
class Solution {
public:

    void findBFS(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int dRow[] = {-1,0,1,0};
            int dCol[] = {0,1,0,-1};

            for(int k = 0; k < 4; k++){
                int nRow = i + dRow[k];
                int nCol = j + dCol[k];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    findBFS(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};


//Approach
//(1) The whole concept behind this is to find the number of DFS or BFS calls. Like the islands are joined together by a set of ones. If we start from one of these ones it covers the whole island. 
//(2) Then for the next Island the DFS is called. Similarly if we keep a track of then DFS calls, then we can find the answer. 
//(3) Make a visited matrix according to the given input. Like each 'one' and 'zero' is like a node and their position in the martix is their respective rows and columns(i & j).
//(4) Call the DFS function for each node in the grid matrix by passing their row and col number as location. 
//(5) First mark it as visited. Then for the unvisited nodes, check if their adjacent nodes in 4 directions are visited or not. Continue the process until all nodes are visited.
//(6) Keep a track of the count in the main function and return the answer.