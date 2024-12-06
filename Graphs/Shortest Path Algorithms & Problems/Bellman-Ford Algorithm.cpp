class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        //Step 1: Create a dist array of size V, mark src node's dist as zero.
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        //Step 2: Iterate for V-1 times and update the dist array with the shorter distances
        for(int i = 0; i < V-1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                } 
            }
        }
        
        //Step 3: We run the iteration one more time to check for negative cycle
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                } 
            }
        
        return dist;
    }
};

//NOTE: Bellman-Ford algorithm questions are pretty much not asked in interviews, it more
//likely a follow up question to Dijkstra's Algorithm to answer the question why for a 
//graph with negative edges, Dijkstra won't work?

//Logic
// Bellman-Ford Algorithm is used to find the shortest distance to every node from the
// src node is there are negative edges. The reason why we can't do this with Dijkstra is that
//as it tries the find the shortest distance everytime, it will keep on adding the negative
//edge weights, leading to a shorter distance everytime we look for one. So it pretty much
//runs infinitely. 

//So here you don't need to make a graph per say, we are given a vector of vectors in which
//each vector contains the edges and and their weight. They can be in any order. We work with this.
//Step 1: Make a dist array with all INT_MAX, dist[src] = 0.
//Step 2: Then we have to make a for loop for n-1 times, where n is the number of nodes. 
//Step 3: Do the same logic for each node in 'edges' we do in Dijkstra, i.e if any smaller
//distance is found for a node in dist array, then update it. Thing to notice is that in 
//standard Dijkstra, we push the src node first with dist 0, so the next adjacent node is
//bound to have it's infinity distance updated by the smaller distance in the dist array.
//But here the nodes in the array doesn't neccesarily have to start with src node, so we 
//need to check if the node's distance we encounter in the dist array is infinity or not along
//with checking if it's adj node has a shorter distance. It's optional(I think), you'll understand
//during the dry run. 
//Step 4: That's pretty much it. Now return the dist array. But the question has asked us 
//to return {-1} if a negative cycle is encountered. How do we do that?

//Logic being negative cycle: So the reason we are doing exactly N-1 interations to update
//the dist array is that at worst case scenario, it will take N-1 times to update all the 
//node's distance in the dist array. Like it reached the end, so any more iterations after
//this should technically not give us any shorter value. BUT if there is a negative cycle
//present, it will give us a shorter value EVEN AFTER we check beyond N-1 iterations. So 
//that's what we are doing. After finishing all the iterations, you check ONE MORE time if 
//you get a shorter distance for any current node. If yes that means there's a negative cycle
//present in the graph. At that point just return -1. 

//Why we're not using queue? If we use a queue we won't get a control for the number of iterations.
//Getting a control for the number of iteration is extremely important if the graph contains
//negative cycles, hence we do it manually. 

//NOTE: The Dijkstra's Algorithm CAN BE used to find shortest path in graphs with negative edges, 
//but NOT WITH grahs with negative edge cycles. 


//NOTE FROM YOUTUBE : Note: The Dijkstra's algorithm implemented in G-32 can handle any negative edges graph EXCEPT the following cases:
// 1- Directed graph having any negative cycle (cycle with sum < 0)
// 2- Undirected graph having any negative edge because the edge in undirected graph is by itself a cycle

//Bellman-Ford can only be used for Directed Graphs. If an undirected graph is given, make 
//the edges vector in such a way that it contains the edges from both u to v and v to u.
//Example = [{1,2,10}, {2,1,10}]
// u => 1
// v => 2
//wt => 10