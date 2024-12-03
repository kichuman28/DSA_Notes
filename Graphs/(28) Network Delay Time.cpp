class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Step 1: Make a graph
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        //Step 2: Make the priority queue for keeping track of the shortest time taken. Push in order{time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k}); //time for src node is zero. Source node is one. 

        //Step 3: Create an array to keep track of time taken to reach from source node to that node.
        vector<int> time(n + 1, INT_MAX);
        time[k] = 0; //time taken to reach the source node itself is zero.

        //Step 4: Traverse the queue and update the time array with the minimum time.
        while(!q.empty()){
            int tm = q.top().first;
            int u = q.top().second;
            q.pop();

            for(auto it : adj[u]){
                int v = it.first;
                int wt = it.second;
                
                if(tm + wt < time[v]){
                    time[v] = tm + wt;
                    q.push({time[v], v});
                }
            }
        }
        
        //The problem here is figuring out the target node. The target node is not essentially the last node (n).
        //I can come around this problem if I just avoid the 0th index (which is always INT_MAX) and just check the 
        //max element among the remaining nodes. If it has INT_MAX then it means there is no path, is something else
        //then we got our answer.
        int ans = 0;
        for(int i = 1; i < n+1; i++){
            ans = max(ans, time[i]);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};