class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool detectCycle(int node, int vis[], int pathVis[], vector<vector<int>> &adj){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(detectCycle(it, vis, pathVis, adj)) return true;
            }else if(pathVis[it]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detectCycle(i, vis, pathVis, adj)) return true;
            }
        }
        
        return false;
    }
};


//Approach
//The main question is why can't the old logic work here? Old logic : if the visited node 
//is not the parent then that means it has been visited by some other node first and there
//fore it is a cycle. The problem here is directed edges. I really can't explain the reason
//here so check out the images or watch the video again. Like the node can be visited by
//some other node but it HAS TO BE ON THE SAME PATH. If if it is not on the same path then
//it is not a cycle. 

//Code
//We need two visited arrays in this case, one for marking the node as visited and another
//for marking if it is along the same path or not. So as we traverse the graph using DFS
//if a path is complete and we did not find any cycles, as we return back in the recursion
//tree you mark that path as unvisited. If there is a cycle then the node will be visited and 
//the path of that node will also be visited. Check out the example in the image.

//TC = O(N + E) Here N is for the loop and E is for the no of edges. Notice here it is not
//2E because it is a directed graph, we are not going through it twice. 