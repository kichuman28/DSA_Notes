class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        set<pair<int, int>> stt;
        
        stt.insert({0, src});
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!stt.empty()){            //Here 'it' is a pair
            auto it = *(stt.begin()); //We use * for accessing the value the pointer i pointing to
            int distance = it.first;
            int node = it.second;
            stt.erase(it);          //equivalent to popping an element from the queue.
            
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(distance + wt < dist[v]){
                    
                    if(dist[v] != INT_MAX){
                        stt.erase({dist[v], v});
                    }
                    
                    dist[v] = distance + wt;
                    stt.insert({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};


//Approach (Dijkstra's Algorithm using Set)
//A set does the same thing as a priority queue. It stores the minimum element in the top.
//So what's the difference? We can use a set to erase elements. Now why erase elements?
//Suppose we came across a node 'u' in the graph that has already been visited and the 
//dist[u] is replaced by some distance 'x' which is less than infinity. That distance 
//along with the node is pushed into the set as {x, u}. Now suppose that same node comes across 
//another distance that is much smaller than x, called 'y'. We replace it in the dist
//array with dist[u] = y and push it into the set as {y, u}. Now tell me, do you need {x, u}
//in the set anymore? We already got a better option with {y, u} so it only makes sense
//to check the adjacent nodes of u with a much smaller distance, which is y. Hence we don't
//need {x, u} anymore. We erase it from the set. 
//Due to this, a set is used. This is not possible in a queue or a priority queue. 
//Not much difference in TC tho because even erase function takes up some time. So it 
//all depends on the question tbh.

//Code
//Same as before, just use a set. Use *(set.begin()) to get the value of the top node. 
//Also we can only erase if we come across a better distance and that node has been changed
//from infinity to some lower distance. So we check if the adjacent node's distance is 
//infinity or not. If it is, we erase. 