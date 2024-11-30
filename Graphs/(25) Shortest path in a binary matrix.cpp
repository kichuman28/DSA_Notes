class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && m == 1 && grid[0][0] == 0) return 1; //Edge case in case the source and destination are the same. There is no path the distance is 0.
        //Step 1: I need to make a priority queue for bfs. I need a pair for the row & col, and an int for the distance.
        queue<pair<int, pair<int, int>>> q;
        
        //Step 2: I need to push the source node and it's starting distance which is one.
        if(grid[0][0] != 0) return -1;
        q.push({1,{0, 0}});

        //Step 3: I need to create the distance matrix. Mark the src node's distance as zer0
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        //Step 4: I need to traverse the matrix in all 8 directions.
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int distance  = q.front().first;
            q.pop();

            for(int dRow = -1; dRow <= 1; dRow++){
                for(int dCol = -1; dCol <=1; dCol++){
                    int nRow = row + dRow;
                    int nCol = col + dCol;

                    
        //In gfg they specifically gave a destination node to return. So we come across the destination node in the for loop we can return it then and there. We don't need to fill in the distance for the rest of the nodes. But here since the distance is the bottom right node, we have to go through the entire matrix.
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                        grid[nRow][nCol] == 0 && distance + 1 < dist[nRow][nCol]){
                            dist[nRow][nCol] = distance + 1;
                            q.push({distance + 1, {nRow, nCol}});
                        }
                }
            }
        }
        //If dist[n-1][m-1] is INT_MAX that means it couldn't take any path to reach there. So return -1.
        if(dist[n-1][m-1] == INT_MAX) return -1;
        return dist[n-1][m-1];

    }
};

// NOTE: IN DIJKSTRA'S YOU DON'T NEED TO ADD THE VISTED ARRAY CONCEPT BECAUSE WE ONLY ADD IN THE QUEUE ONLY IF THE DISTANCE IS SMALL. THAT IS THE CONDITION HERE. DON'T NEED THE VISITED ARRAY CONCEPT.

//Approach
//They did ask to find the shortest path. I can use the Dijsktra's algorithm here. 
//For the algo U need the ordering of the nodes properly. 
//Similar to the matrix questions, I can do a BFS here to go to all the nodes in 8 directtions if it is vis AND if the element is a zero as well. 
//I need another matrix to keep track of the distance from the source node as well. This is like the dist array. 
//I need to start from (0, 0) & end up at (n-1, m-1).
//The problem to solve is how to keep track of the shortest distance in the dist array. 
//I don't need to keep track of it. The final element in the dist array (n-1, m-1) already has the shortest distance it needs. Just return it.
//Also you don't need a priority queue, you can do it with a queue as well because it already stores it in the ascending
// order due to the nature of the bfs