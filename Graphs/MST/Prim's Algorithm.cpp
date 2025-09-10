class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // I have to make the graph
        vector<vector<pair<int, int>>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> vis(V, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        q.push({0, 0});
        
        int sum = 0;
        
        while(!q.empty()){
            int weight = q.top().first;
            int node = q.top().second;
            q.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += weight;
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(!vis[v]){
                    q.push({wt, v});
                }
            }
        }
        
        return sum;
    }
};

//Prim's Algotithm to get the MST/Minimum Spanning Tree
//MST is a sub graph where all the nodes are connected to each other and the sum of the 
//edges is the minimum. Useful for finding out the least distance route between a set of 
//connected components etc. A spanning tree always n-1 edges. 

//Now with Prim's Algorithm, I can find the sum of the total minimum distance and the 
//edges that contributed to it. But here I only need the sum. 

//I need a visited array to keep track of the nodes.
//A variable to keep track of the sum
//A priority queue in the order {weight,{node, parent}}
//A vector of pairs to store the edges of the MST (Not required here)

//Steps
//I first need to insert {0, {0, -1}} into the pq. -1 represents the first node, which has
//no parent. 
//Then, until the queue gets empty I take out the top node from the pq.
//I take out the weight, node and parent node.
//Then I visit these nodes (before checking the adjacent nodes). 
//Inside that check condition, I check if the parent node is not -1 or not. If it is not -1
//then I add it to the edges vector of pairs else I don't add it. 
//Then I iterate through the node's adjacent nodes. Check if they are not visited. 
//If not visited, then I add the weight to the sum variable. 
//Then I add that weight, node & parent into the PQ. 
//Repeat until the queue gets empty. 
//Finally return the sum. 


//Intuition: Basically a greedy approach. I try to find the path with min edge weight and
//continue with it. 

//TC: O(E Log E): While loop takes E. top() function takes log E. So overall E log E. Now
//for inside the adjacent node for loop, at worst case, all the adjacent nodes will be
//check. So that's another E. Then inside the for loop there is a push operation which takes
//another log E, so that's E Log E.
//So E Log E + E Log E ~ E Log E as total TC.
//SC: O(E) for the pq.