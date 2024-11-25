class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //Step 1 : Make the graph. Here in edges, each pair represents an edge. [u,v].
        vector<vector<int>> adj(N);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u); //Since it's an undirected graph
        }
        
        
        queue<int> q; //Pushing the starting node into the queue.
        q.push(src);
        
        vector<int> vis(N, 0); //Marking the starting node as visited.
        vis[src] = 1;
        
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;          //Mark the dist of the source node as 0.
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    if(dist[node] + 1 < dist[it]){
                        dist[it] = dist[node] + 1;
                        q.push(it);
                    }
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};



//Approach
//This is the same concept as finding the distance of nodes in a DAG with weights. Except
//here it is not a DAG and I don't have to worry about the correct ordering. 
//So I do a BFS traversal on the graph since it goes in a level order way I can compare
//the distances accordingly. The queue will contain the node and distance.
//I also initialise another array called thh distance array where I initialise all the nodes
//as infinity. I mark the source node's distance as 0 and also push the source node along
//with it's distance into the queue. 
//Now until the queue is empty, I take out each node, check if the distance to it's adjacent 
//node with the distance added from the current node is less than the distance of the adjacent
//node which is already initialised as infinity in the distance array. If yes I replace the dist
//array with that and push it into the queue.
//This process is repeated until the queue is empty.


//You can also do it by only adding the nodes in the queue. Then while comparing you can
//check if dist[node] + 1 < dist[it]. You don't need to seperately add the distance for 
//each node, that's why we made a dist array and initialised the src node's distance as 0.


//Why we use queue and not some algorithm to sort the nodes like how we did for DAG using topo sort?
//Here since we are using BFS with a queue and it's only unit distance (1) and not some random
//numbers it is going level by level. So we know each level will get incremented by a distance of 
//only 1. It's common sense to be honest. TC is same as BFS = O(V + 2E) 2E because it is an 
//undirected graph.