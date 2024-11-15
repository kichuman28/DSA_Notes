class Solution {
public:
    bool detectBipartite(int start, int color, vector<int> &vis, vector<vector<int>>& graph){
        vis[start] = color;

        for(auto it : graph[start]){
            if(vis[it] == -1){
                if(!detectBipartite(it, !color, vis, graph)) return false; //Check image
            }else if(vis[it] == color){
                return false;
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(!detectBipartite(i, 0, vis, graph)) return false;
            }
        }
        return true;
    }
};

//Approach
//What is a bipartite graph? Basically when you color a graph with two colors, say 0 and 1, no two adjacent nodes should have the same color, i.e every adjacent node must have a different color. 
//For cycles with even length, they are bound to be a bipartite graph.
//For cycles with odd length, they are bound to be not bipartite. 
//Intuition: We just need to mark all the nodes color by color and at some point if two nodes have the same color then it means it is not a bipartite graph. 

//How do we mark the colors? Instead of using a visited array full of zeroes, we use an array initialised with -1. 
//Then we go through each node in the graph and check if it is uncolored or not (-1 or not). If it is not colored then we mark it as the color opposite to the parent node(To start off, we mark the parent node with some color).
//Next if it is already colored, then we check if it has the same color as of the parent node. If it does then we return false.
//Now if the whole graph is traversed it means there are no adjacent nodes with same color, so we return -1.
//TC = O(N + 2E) N is for the while loop, 2E refers to the traversal of all the edges in the graph, it does it TWICE 

//Incase it is not getting accepted it is because we are not considering the concept of connected components graph. So keep that in mind. 