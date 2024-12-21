
class Solution {
  public:
  
  
    bool findDFS(int node, int vis[], int pathVis[], vector<int> adj[], int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(findDFS(it, vis, pathVis, adj, check)){
                    check[node] = 0;
                    return true;
                }
            }else if(pathVis[it] == 1){
                check[node] = 0;
                return true;
            }
        }
        
        
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int pathVis[V] = {0};
        int vis[V] = {0};
        int check[V] {0};
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                findDFS(i, vis, pathVis, adj, check);
            }
        }
        
        vector<int> safeNodes;
        for(int i = 0; i < V; i++){
            if(check[i]){
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};


//Approach
// So it's pretty much the same concept as detecting cycles in a directed graph. Here a safe node
// refers to a node that doesn't point to other nodes that ends up in a cycle. Refer the example
// in the image for more reference. So really all we have to do is take a note of all the nodes
// that end up in a cycle in a directed grapg. The nodes which do not end in a cycle? We return 
// that as the as answer by storing it in a vector.

//How to do this?
// Literally the same code & almost same logic as the cycle detection in a directed graph question.
// In the main function we need an array called check[], which takes a note of which all nodes
// are visited or not. So in the main function when we go through all the nodes via for loop
// (connected components concept), we don't return true if a cycle is found. We need to mark
// the other nodes in the cycle in the path vis array as well for future calls (either watch
// video or look at image for reference. In the image inorder for node 11 to say that node 9
// ends up in a cycle, the entire dfs call must continue from node 8, where the cycle is first
// encountered. Then only the pathVis array will have that node marked as 1). If there is no
// cycle the pathVis for those nodes will be 0, if there is path, then those nodes are not 
// unmarked. 

//TC = same as DFS : O(N + E)
//SC = Using 3 arrays