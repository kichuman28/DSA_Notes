  class Solution {
  private:
    bool detectCycle(int node, int parent, vector<vector<int>>& adj, int vis[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(detectCycle(it, node, adj, vis)) return true;
            }else if(parent != it){
                return true;
            }
        }
        return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n] = {0};
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(detectCycle(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};

//Approach (Doing this one using DFS)
//(1) The concept is same here similar to BFS. Keep a visted array for each node and mark it as one if it is visited.
//(2) If one of the adjacent node is visited and it is not the parent node of the main node
//then it means that node is visited by some other node. Return true.
//(3) Only difference here is that DFS works on recursion. So it will keep on going until it
//gets true. So you have to keep a condition inside the !vis[it] if condition to return true
//incase a true is returned. You don't have to check further.

//SC = O(N)
//TC = O(N + 2E) because it visits all the nodes + O(N) for the for loop in main function.