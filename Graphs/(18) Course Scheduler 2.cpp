class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(count == numCourses) return ans;
        return {};
    }
};

//Approach
//This again is the same concept. In the first problem they just wanted to know if a cycle exists or not. Here if the cycle does not exist they just want to return the actual ordering, which we did in topological sort. Since topological sort is the linear ordering in DAG such that u comes before v, we can just do that & return the ordering. Only thing you have to be careful about is that incase a cycle is detected, it still adds in the nodes till the cycle is encountered to the ans array. So to prevent returning that half filled array, we have to check if the size of the array is same as the number of nodes, then only topo sort condition is satisfied. Or else we can just return an empty array.