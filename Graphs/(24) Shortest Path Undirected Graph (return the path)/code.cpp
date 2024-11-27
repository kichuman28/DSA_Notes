class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        //Step 1: Make the graph. We are using 1 based indexing so use n+1 as size everywhere.
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        
        //Step 2: Make the dist array and mark the src node's dist as 0
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0; //Here the source node is 1.
        
        //Step 3: Make a priority queue (min heap) & push the src node into it
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1}); //{distance, node}
        
        //Step 4: Make a parent array, initialise everything as zero
        vector<int> parent(n + 1, 0);
        
        //Step 5: Traverse the queue, update the dist array
        while(!q.empty()){
            int distance = q.top().first;
            int u = q.top().second;
            q.pop();
            
            
            for(auto it : adj[u]){
                int v = it.first;
                int wt = it.second;
                
                if(distance + wt < dist[v]){
                    dist[v] = distance + wt;
                    q.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        
        //Step 6: If the end node is not connected to the src node then there is no path. We have to return a vector with -1.
        if(dist[n] == INT_MAX) return {-1}; 
        
        //Step 7: Make an array to store the answer. First push the end node's distance into the ans array from the dist array
        vector<int> ans;
        ans.push_back(dist[n]);
        
        
        //Step 8: Traverse the parent array to backtrack and receive the parent nodes
        int start_node = n;
        vector<int> temp;
        while(parent[start_node] != start_node){ //We traverse until the src node is reached.
            temp.push_back(start_node);
            start_node = parent[start_node]; //Refer image for understanding. Common sense really.
        }
        temp.push_back(1); //here the src node is not inserted because the condition in the while loops states if the src node is reached then you have to exit. Hence we added the source node manually.
    
    
        //Moodiying the answer according to the question
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < temp.size(); i++){
            ans.push_back(temp[i]);
        }
        
        return ans;
    }
};

//Approach 
//Here we have to find the shortest path and between the source node and the end node.
//Instead of returning the shortest distance we have to return the path taken to reach that
//shortest distance.
//We can find the shortest distance of all the nodes via Dijkstra's algorithm. We need a 
//way to keep track of the nodes. This is where we use a parent array.
//So we declare a parent array maybe all initialised with zeroes. Each time we get a new node
//from the priority queue and check it's adjancent nodes, if we find a node with a smaller 
//distance we add it to the queue and also update it's parent in the parent array. 
//Now after all the traversal is done in the priority queue we now have a parent array which
//keeps track of all the nodes from which it came from
//So in the end we can just backtrack by checking the parent array from where the end node's
//parents came from.


//TC = Dijkstra + time taken to access the parent array. At the worst case it can go till N, i.e all the nodes(linear)
//TC = O(M log N + N)