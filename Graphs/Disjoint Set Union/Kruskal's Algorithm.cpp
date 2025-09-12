class DisjointSetUnion{
  vector<int> size;
  vector<int> parent;
  
  public:
  
    DisjointSetUnion(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int U = findParent(u);
        int V = findParent(v);
        
        if(U == V) return;
        
        if(size[U] < size[V]){
            parent[U] = V;
            size[V] += size[U];
        }else if(size[V] < size[U]){
            parent[V] = U;
            size[U] += size[V];
        }else{
            parent[V] = U;
            size[U] += size[V];            
        }
    }
};



class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // I have to make the graph

        vector<pair<int, pair<int, int>>> adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj.push_back({wt,{v,u}});
        }
        
        sort(adj.begin(), adj.end());
        int sum = 0;
        
        
        DisjointSetUnion ds(V);
        
        for(auto it: adj){
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            
            
            if(ds.findParent(node) != ds.findParent(parent)){
                sum += wt;
                ds.unionBySize(node, parent);
            }
        }
        
        return sum;
    }
};

//Kruskal's Algorithm
//The base for this algorithm is Disjoint Set Union. 
//What we have to do is to first organize all the nodes in the graph according to their
//weight in the order {weight, node, parent}. Mostly in a priority queue.
//Next we start with the nodes with the smallest weight. Check if the boss node of the 
//node and parent are the same or not. 
//If not then we join them by Union function then add the weight simulataneously.
//If the parents are the same then we ignore that node edge/weight. 
//Keep on doing this until the queue is empty
//Finally return the weight.