class Solution {
  public:
    //Cycle detection in a cyclic graph using BFS
    bool isCyclic(int V, vector<vector<int>> adj) {
        int n = adj.size();
        queue<int> q;
        
        int indegree[n] = {0};
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        int m = topo.size();
        
        if(m == n) return false;
        
        return true;
    }
};


//Approach
// Topo sort only works for Directed Acyclic Graphs. The definition of TOPO sort is the linear
// ordering of "N number of nodes" such that u comes before v. All the nodes should be there
// in the topo sort. If the number of nodes is less than N, then that means it isn't a Directed
// Acyclic Graph. So we can use this intuition to detect whether there exists a cycle in a directed
// graph. If we do the topo sort for a cyclic graph then we'll only get 1 node or something
// not the entire thing. Check image for reference.

// 1) Do a topo sort for the given graph
// 2) Check the size of the topo sort. If it is equal to N then it means there is no cycle.
// 3) If it less than N it means there exists a cycle.

//TC = O(N + E) Only single E because of directed graph, only goes through all nodes once.