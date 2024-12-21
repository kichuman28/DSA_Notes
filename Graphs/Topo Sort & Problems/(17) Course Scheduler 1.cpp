class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for(auto& it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto& it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto& it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return count == numCourses;
    }
};

// Approach
//If we read the question we can understand that the question is basically the rules of topo sort. 
// That one course should come before the another. If the courses ends up in a cyclic dependency then it means
// it's not valid. So this is basically Cycle Detection in a Directed graph. We can do it using DFS(pathVis concept) 
// or BFS(Kahn's Algorithm) concept. I'm doing it in BFS becausse Course Scheduler 2 demands BFS. So basically just do
// cycle detection in a directed graph via topo sort method. The only thing you have to be careful here is how to make the graph.
// Also from now onwards always use '&' in after 'auto' when you use it in loops. 
//TC: Same as BFS, O(N + E), only single E because it is directed, all nodes are visited only once.