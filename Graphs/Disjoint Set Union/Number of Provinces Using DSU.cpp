class DisjointSetUnion{
    vector<int> parent;
    vector<int> size;

    public: 
        DisjointSetUnion(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int node){
            if(parent[node] == node) return node;

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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        DisjointSetUnion ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                    cout << i << ':' << j << endl;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(ds.findParent(i) == i){
                count++;
            }
        }

        return count;
    }
};

//Solving this using Disjoint Set Union
//Intuition: The number of boss nodes = number of components. 
//So I have to find a way to find the number of boss nodes. 
//In DSU, I can find the boss node using the findParent function. It's exit condition will 
//help us here. 
//If the parent of a node is itself, then it means we found the boss node, as the boss node
//does not have a parent. So it is it's own parent. 

//Code:
//Just run a for loop across all the nodes in the graph and find their ultimate parents. 
//If it is the same node, increase the counter and finally return it. 