class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        
        int n = adj.size();
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        q.push({0, src});  //distance, then node. The order is important
        
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()){
            int distance = q.top().first;
            int u = q.top().second;
            q.pop();
            
            
            for(auto it : adj[u]){
                int v = it.first;
                int wt = it.second;
                
                if(distance + wt < dist[v]){
                    dist[v] = distance + wt;
                    q.push({dist[v], v}); //distance, the node.
                }
            }
        }
        
        return dist;
    }
};


//Approach 
//The logic is same as in the questions such as finding shortest path in DAG and shortest path in
//an undirected graph with unit weights, more closely to the second one. 
//Here instead of a normal queue we use a priority queue. We can also use a queue but pQueue is 
//faster.
//Step 1: Graph is already given with each index having the adjacent nodes along with their weights
//in a pair. 
//Step 2: Create a priority queue, with the distance and the node. The distance should come before
//the node. The order is important. Using a priority queue allows us to use the concept of min heap.
//So in a pqueue, the smallest element is stored first. First we check based on the smallest distance.
//If the distance is same then we check the order of the nodes. This is the concept of min heap.
//Step 3: Create a dist array with everything set to infinity. Mark the distance of the source node as 0.
//Step 4: Now traverse the queue and take the front node, check it's adjacent nodes for smallest
//distances, if found update the array and push it into the queue. Same concept as before.
//Step 5: Repeat until queue is empty. Return the dist array.
//NOTE: Don't have to use -1 as the distance for the nodes which are not connected to the source node
//as it is mentioned in the question that all the graphs are connected graphs.

//Why is Dijkstra's algorithm not applicable for graphs with negative weights? (Refer Image)
//TL:DR If we use negative values everytime we will get a smaller value than tthe current value
//and we push that into the queue. This will go on infinitely and it will never stop. Hence
//it won't work for graph with negative weights.

//TC = O(E log V).