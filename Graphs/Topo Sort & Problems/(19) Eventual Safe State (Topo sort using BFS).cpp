class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i); // these two lines are where the reversal happens
                indegree[i]++;        // this one too
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};


//Okay you did this one before in GFG using DFS. Now we're trying to do BFS. We're using the same concept of topo sort as in both questions we want nodes that don't end up in a cycle. Well this isnt technically topo sort as we're only return the number of nodes that do not end up in a cycle. The definition of topo sort is the ordering of ALL the nodes that do not end up in a cycle and such that u comes before v. Here not all nodes are there, but only the nodes that do not end up in a cycle. It's like we're partially using the concept of BFS here. 

// NOTE: Topo sort using DFS is via a stack, don't confuse everything. REVISE

// 1) Now the first thing we need to do in topo sort via BFS is to find the nodes with indegree = 0. Since the terminal nodes are always the part of the answer we can start from there. Their outdegree will always be zero so if we just reverse it their indegree will be zero so will the direction of the edges. 
// 2) Now we have reversed the graph we can do the standard Topo sort. Here we don't have to check if the size of the answer array is equal to the number of nodes, we just need the nodes that don't end up in an array.
// 3) You also have to reverse the final array with the nodes because since we reversed the graph we'll be getting a reversed order. So to get the correct order we have to reverse the graph again.
//TC = O(V + E)