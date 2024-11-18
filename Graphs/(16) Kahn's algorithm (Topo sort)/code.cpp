class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    void findDFS(int node, vector<int> &vis, vector<vector<int>>& adj, stack<int> &stt){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                findDFS(it, vis, adj, stt);
            }
        }
        
        stt.push(node);
    }
    
    
    
    
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> stt;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                findDFS(i, vis, adj, stt);
            }
        }
        
        vector<int> ans;
        while(!stt.empty()){
            ans.push_back(stt.top());
            stt.pop();
        }
        
        return ans;
    }
};

//Approach
// So the definition of Topological Sort : The linear ordering of nodes such that if there is an
// edge from u to v, u should come before v in that ordering. This is possible only for
// Directed Acyclic Graph (DAG). Now why both Directed & Acyclic?
// i) Directed : If it is an undirected graph then that means the edges can go both directions.
// That will contradict the definition as if there's a direction from two edges (vice versa) then
// it is impossible for one to come before the other.
// ii) Acyclic : If it is cyclic then again it will contradict the definition as one node can't
// come before the other if it ends up in a cycle. 

//Logic
// So to get that linear ordering, it's pretty much the same concept. We use a stack here this
// time instead of a queue. We use the connected components concept here as well. If a node is not
// visited we call the dfs function to push it into the stack. Inside the function we check if
// it's adjacent nodes are unvisited as well to push into the stack. If not it'll not go down
// that recursive path, mark it as visited and push itself into the stack after checking IT"S 
// adjacent nodes. Standard recursion. 

//Intuition 
// If we use a stack, like whatever nodes we push inside the stack? It means all the adjacent nodes
// of that nodes is also visited..so there's like no more nodes to visit. So it comes in that
// correct ordering. 


//TC = O(N + E) because of directed graph. 