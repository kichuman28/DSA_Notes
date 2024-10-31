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
        vector<int> adjLs[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                findDFS(i, vis, adjLs);
            }
        }

        return count;
    }
};