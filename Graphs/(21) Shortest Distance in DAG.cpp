class Solution {
  public:
  
  
    void topoSort(int node, vector<vector<pair<int, int>>> &adj, stack<int> &stt, int V, vector<int> &vis){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first; //{node, weight} this is done for accessing the value of the node from the pair
            if(!vis[v]){
                topoSort(v, adj, stt, V, vis);
            }
        }
        
        
        stt.push(node);
    }
  
  
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        
        //Step 1: Make the graph
        // We need to make a graph, here they've only given the edges and their weights.
        // Here V is the number of nodes, E is the number of edges.
        vector<vector<pair<int, int>>> adj(V); // or vector<pair<int, int>> adj[V] works as well. Standard representation is vector<vector<int>> for graphs with  no weights. But since here there is a weight, along with adjacent node we also add the weight along with it in the form of a pair.
        for(auto it : edges){
            int u = it[0]; //node u
            int v = it[1]; //node v
            int wt = it[2]; //weight of the edge from node u to node v.
            adj[u].push_back({v, wt}); //We represent graphs with weights as a pair. pair.first is the adjacent node, pair.second is the weight.
        }
        
        
        //Step 2: Do the topo sort, either via bfs or dfs
        vector<int> vis(V, 0);
        stack<int> stt;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topoSort(i, adj, stt, V, vis);
            }
        }
        
        //Step 3: Make a distance array for storing the initial distance. Mark the distance of source node as 0
        vector<int> dist(V);
        for(int i = 0; i < V; i++) dist[i] = 1e9;
        dist[0] = 0;

        //Step 4: Traverse the topo sort and compare the weights from the graph and update the dist array.
        while(!stt.empty()){ //TC = O(V + E)
            int node = stt.top();
            stt.pop();
            
            for(auto it : adj[node]){  //Here it represents each pair in the vector, which is inside another vector. v is the adjacent node and wt is the weight of the edge between u and v
                int v = it.first;       // [ [{1, 4}, {2, 1}], [{2, 2}], [{0, 7}, {3, 3}] ] THis is how adj looks like
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == 1e9) dist[i] = -1; //So the question and the corresponding solution for the question discussed by the striver bhaiya have been changed(It seems like the problem setter has worked on it. the one that striver bhaiya was talking about)
                                            // So as per the current question, we have to return -1 when we aren't able to reach the node from the source node.
                                            // So we just have to add and modify the code at the end :- 
                                            // for (int i = 0;i < N;i++)
                                            //       if (dist[i] == 1e9) dist[i] = -1;
                                            // Just add these two lines before returning the answer.
                                            // The whole code looks like this :-
                                            //Basically a connected component. If it is not connected to the source node, it's distance always stays as 1e9. So we just need to change it to -1.
        }
        
        return dist;
    }
};


//Approach
///Okay so here they have given us a vector of vectors containing the nodes and their weights,
//Three elements in one vector, a[0] is node u, a[1] is node v, a[2] is the weight of the edge
//between node u and node v. That's the edges matrix.
//Now we have to return the minimum distance from the source node to every other node in the graph
//by taking note of the the weight in the edges matrix and return it in the form of an array.
//Like each index in the array is a node, and their value is the minimum distance from the source node.
//Here the source node can be anything. It doesn't have to always be zero. 

//Step 1: Do a topological sort of the nodes. You can do BFS or DFS, we just need the linear ordering. 
//We are doing topo sort only because this is a directed acyclic graph. It won't work on a graph
//with cycles. The intuition is written after everything.
//Step 2: Now we make a distance array and initialise each element as infinity, assuming that's
//initial distance for each node from the source node. 
//Step 3: Now we mark the distance for the source node as 0, as the distance from source node to 
//itself is always zero, commmon sense. 
//Step 4: Now starting from the source node (the source node will always be the first node in the 
//topo sort linear ordering), we start taking the adjacent nodes from the adj matrix.
//Step 5: We compare the weight of the adjacent node by adding it with it's weight from the 
//adj graph AND the weight of the main node (dist[node] + wt). dist[node] just tells us the 
//total distance from the source node for that main node. We add it with the distance to the adjacent
//node. So we compare (dist[node] + wt) with dist[adjacentNode] which is initially infinity.
//Step 6: If it is less, it replaces infinity and this process keeps on repearting for further
//nodes in the graph. If we come across any other nodes with less weight then it will replace that 
//as well.

//Intuition: We use topo sort because it is easier to find out the shortest distance of a node
//from the source node if we know the shortest distance of all the nodes that precedes it. 
//Knowing the shortest distance of all the preceding nodes is only possible via topo sort to 
//get that correct linear ordering. 


//TC = Same as DFS. O(V + E). Then for the while loop, at max we visit all the nodes and it's adjacent nodes as well. So it's
//TC is O(V + E) as well.
//SC = stack, array etc