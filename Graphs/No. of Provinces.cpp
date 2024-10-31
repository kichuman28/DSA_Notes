class Solution {
public:

    void findDFS(int node, vector<int> &vis, vector<int> adjLs[]){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                findDFS(it, vis, adjLs);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        int m = adj[0].size();
        vector<int> adjLs[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                findDFS(i, vis, adjLs);
            }
        }

        return count;
    }
};

//Approach
//(1) First convert the given adjacency matrix into an adjacency list.
//(2) Next we just need to get a count on how many times the DFS traversal has been called on all the connected components. If the vis array is not marked then only we call the dfs function.
//(3) Just return the count after that.