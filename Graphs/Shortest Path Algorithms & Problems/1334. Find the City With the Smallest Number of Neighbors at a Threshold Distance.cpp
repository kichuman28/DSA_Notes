class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Step 1: Make the adjacency matrix
        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for (int i = 0; i < n; i++) {
            mat[i][i] = 0; // Distance from a city to itself is 0
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j],
                        mat[i][k] + mat[k][j]);
                }
            }
        }

        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= mini){
                ans = i;
                mini = count;
            }
        }

        return ans;
    }
};

//My Approach. 
//The question is simple really, all they're asking is to find the cities with path weights less than the threshold value
//So all I need to do is use FW algorithm and calculate the shortest path from each node to every other node.
//Then I need to traverse it and check for the values less than or equal to the threshold value. If yes, then add those edges into another adjacency list (kinda)
//Then check that list for the size of each vector and find the one with the minimum size. Keep on finding it till the end of the vector because if there are equal sizes then we need the city with the highest number, since the vector is in ascending order, this will help.


//NOTE: While making the matrix make sure the diagonals are zero, or it won't work.