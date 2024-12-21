class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Step 1: Create a graph
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }


        //Step 2: To create a normal queue, because I don't want the shorter one to replace it quick, i.e k matters more than the shortest path.
        //The queue will have to keep a track of 3 things, the price, the node and a variable to keep track of the steps?
        queue<pair<int, pair<int, int>>> q;

        //Step 3: Push in the src node with dist  = 0, steps = -1.
        q.push({0, {src, -1}});

        //Step 4: Create a price array to keep track of the price for each node. 
        vector<int> price(n, INT_MAX);
        price[src] = 0;

        //Step 5: Traverse the queue until it is empty and update the price array
        while(!q.empty()){
            int u = q.front().second.first;
            int cost = q.front().first;
            int stops = q.front().second.second;
            q.pop();

            for(auto it : adj[u]){
                int v = it.first;
                int wt = it.second;

                if(stops + 1 <= k){     //We put more concentration on the stops because even if the price is high the no. of stops should be strictly maintained. The reason we are adding +1 is because the stops haven't updated yet. We are checking if the stops can be satisfied before pushing the next element into the queue. So by the time the stops are satisfied dist[dst] MUST have some value. If it does then return it or else it will be INT_MAX which in that case we will return -1.
                    if(cost + wt < price[v]){
                        price[v] = cost + wt;
                        q.push({price[v],{v, stops + 1}});
                    }
                }
            }
        }

        if(price[dst] == INT_MAX) return -1;
        return price[dst];
    }
};

//TC = O(E)
//Dijkstra's tc is O(E Log V) but since we are not using the priority queue here we can remove Log V. There the TC is just E which is the number of nodes, in this case it is heights.size();