class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        //Step 1: Create a pq
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0,{0,0}}); //Push the source node into the queue with distance 0.

        //Step 2: Create a dist matrix with infinity, mark the src node's distance as 0. We store the abs diff over here.
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        //Step 3: Traverse the queue and update the diff array.
        while(!q.empty()){
            int row = q.top().second.first;
            int col = q.top().second.second;
            int diff = q.top().first;
            q.pop();

            //Return the dist if we reach the end point, i.e n-1, m-1
            if(row == n-1 && col == m-1) return diff;

            //Check all the 4 directions for possible movements
            for(int i = 0; i < 4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                    //Now find the maximum difference between the current element & new element
                    int newEffort = max(abs(heights[row][col] - heights[nRow][nCol]), diff);
                    //Now we check if the newEffort is less than dist[nRow][nCol] like (dist[u] + wt < dist[v])
                    if(newEffort < dist[nRow][nCol]){
                        dist[nRow][nCol] = newEffort;
                        q.push({newEffort, {nRow, nCol}});
                    }
                }
            }
        }

        return 0; //If the end point is unreachable the dist is 0
    }
};

//My approach
// Just watch the damn video there's no way I'm writing the explantion for this
// tl:dr => I need to find the max differences for each path, then out of all the maximum diffrences, I need to return the minimum difference. So set the diff matrix with the maximum diffrences and add it to the pq, from there the pq just gives me the minimum distance of them all. 