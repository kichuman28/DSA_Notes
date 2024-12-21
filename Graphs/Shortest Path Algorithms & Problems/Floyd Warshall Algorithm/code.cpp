class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 1e9;       //We are doing this for comparison purposes, optional. While returning we have to change it back to -1.
                }
                if(i == j) mat[i][j] = 0;
            }
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], 
                        mat[i][k] + mat[k][j]);
                }
            }
        }
        
        
        //Incase negative cycles are present, we just have to check if the diagonal elements have value less than zero
        // for(int i = 0; i < n; i++){
        //     if(mat[i][i] < 0) return "Negative cycle exists";
        // }
        
        
        
                
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1e9){
                    mat[i][j] = -1;
                }
            }
        }
    }
};


//Approach
//So Floyd-Warshall Algorithm is basically used to find the shortest path from EVERY SINGLE
//NODE in the graph. Like there's no finding the shortest path from only the src node, we 
//find it for every node. We can do this via Dijkstra as well, we just have to run the 
//algorithm for every single fucking node, which will give us a TC of N * E log V, where N
//is the number of nodes. But there's a catch. If there is negative cycles then this appraoch
//fails. That's where Floyd Warshall Algorithm comes into play.

//So in FW algorithm instead of using adjancency list we use adjacency matrix. The matrix 
//bascically contains the weight of edge between two nodes, the two nodes are repsresented 
//in the matrix as mat[u][v]. The diagonals of this adjanceny matrix will always be zero
//because you don't need any distance to reach the same node itself. This happens when u
//becomes equal to v.

//Intuition: There's pretty much no intuition to this algorithm. It's more of a brute force
//where all combination of paths have been tried to get the shortest path. It's a simple brute
//force on all paths. Focus on the 3 for loops

//This one is similar to the matrix multiplication formula 
//matrix[i][j] = matrix[i][k] * matrix[k][j]
//Except here instead of k, we're using 'via' which is all the nodes in the graph. 
//Like we go through each and every possible combination of via and take the min from that.
//Here the formula will be like
//matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j])
//You keep on doing this for all the values of via we get the final ultimate matrix which
//consists of the shortest path from anu given node to the other.


//How does this work for negative cycles?
//If a negative cycle exists then the diagonal elements will have a negative value. Like
//the distance to reach the src node should be zero but incase there's a cycle with negative
//values(positive values is fine because it'll always take the minimum which is zero) then
//if we consider the path weight it will be less than zero. So if it less than zero we 
//can say a negative cycle is present.

//TC = O(N^3)
//SC = O(N^2) ;- We are using the given matrix for doing the problem, so it's space is O(N^2).
