class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0)); //O(NxM) 
        queue<pair<pair<int, int>, int>> q; //O(NxM)

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j}, 0});
                }
            }
        }

        int tm = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);


            int dRow[] = {-1,0,1,0};
            int dCol[] = {0,1,0,-1};
            for(int i = 0; i < 4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];


                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == 1 && vis[nRow][nCol] != 2){
                    q.push({{nRow, nCol}, t+1}); //make sure you don't use t++ here it won't work
                    vis[nRow][nCol] = 2;
                }
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return tm;
        
    }
};


//Approach
//(1) First I need to find the rotten oranges in the given matrix and mark it as rotten in the vis matrix.
//(2) After that I need to create a queue with a pair(represents postion of rotten orange) and int variable (represents time). 
//(3) Then I have to push the positions of the first rotten oranges into the queue with time=0.
//(4) Next I have to run a loop until the queue is empty. First take the first element in the queue and then pop it
//(5) Run a check for max time.
//(6) Next check the adjacent elements in all the four directions and if they are fresh and they are not marked as rotten in the visited matrix, add it to the queue along with it also increment the timer. 
//(7) Finally you have to check the visited matrix if there are any oranges that are not marked (not 2) and the corresponding position in the 'grid' matrix should be 0(i.e not there). If it is not marked as 2 and the corresponding position in the 'grid' matrix is 1, then that means we could not reach all the oranges in the grid and we should return -1. 


//TC = O(NxM).
//SC = O(NxM) for recursive stack space + O(NxM) for queue. At max all oranges in matrix can be rotten hence O(NxM).