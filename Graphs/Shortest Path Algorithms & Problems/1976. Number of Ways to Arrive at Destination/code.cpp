class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Step 1: Make a graph
        vector<vector<pair<long long, long long>>> adj(n);
        for(auto it : roads){
            long long u = it[0];
            long long v = it[1];
            long long wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        //Step 2: Make the pq with {dist, node}. Push in the src node with dist 0.
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        q.push({0, 0});

        //Step 3: Make the dist array with everything as INT_MAX, except the src node with a distance of 0.
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        //Step 4: Make an array 'stops' which keeps track of how many times I can reach the same stop from the src node.
        vector<long long> stops(n, 0);
        stops[0] = 1;

        //Step 5: Traverse the queue until it is empty, update the dist and stops array
        long long mod = 1e9 + 7;
        while(!q.empty()){
            long long u = q.top().second;
            long long distance = q.top().first;
            q.pop();

            for(auto it : adj[u]){
                long long v = it.first;
                long long wt = it.second;
                if(distance + wt < dist[v]){
                    dist[v] = distance + wt;
                    stops[v] = stops[u];
                    q.push({dist[v], v});
                }else if(distance + wt == dist[v]){ //You found another way to reach the same node
                    stops[v] = (stops[v] + stops[u]) % mod;
                }
            }
        }

        
        return stops[n-1];
    }
};

//Approach 
//In hindsight, this pretty much looks like a standard Dijkstra's Algorithm problem. 
//So here you need to return the number of times you have reached the end node. So I can just do the usual
//Dijkstra's implementation and maintain an array called stops. What this array does is that everytime I come across
//a node in the graph and it's distance is not INT_MAX in the dist array AND if the new distance is the same as the old
//distance then you increment that elements position in the stops array by one. Initialise all elements in the stops
//array as one because as stated in the question there is atleast one path from one node to every other nodes.
//Finally return stops[n-1] as the answer.


//So there's a mistake in the stops array implementation. It's basically keeping a track of the number of ways you can 
//reach the same node. So in the beginning, mark the src node's stops as 1 as there is only one way to reach the src node
//from the src node itself. Each time you find a shorter distance, then it means that adjacent node's (v) stops will be the
//same as it's main node (u).
//In case I find another shorter path then the stops of the new node (v) will be the older stop + the current stops. 