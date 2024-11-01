  private:
    bool detectCycle(int node, vector<vector<int>>& adj){
        int n = adj.size();
        int vis[n] = {0};
        queue<pair<int, int>> q;
        vis[node] = 1;
        q.push({node, -1});
        
        while(!q.empty()){
            int main = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[main]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, main});
                }else if(parent != it){ // one of the nodes must be marked because of the parent node. if the other one is not marked then it means it is visited by some other node. Hence return true.
                    return true;
                }
            }
        }
        return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code for connected components
        int n = adj.size();
        for(int i = 0; i < n; i++){
            if(detectCycle(i, adj)){
                return true;
            }
        }
        
        return false;
    }
};


//Approach
//(1) We have to do a BFS traversal here. We need to make some slight modifications in the 
// queue data structure. If we do BFS and one of the nodes reach before the other node reaches
// then we know it's a cycle. That's the whole concept. 
//(2) To show that, we add one more variable inside the queue called 'parent node'. 
//(3) While adding the nodes into the queue we also add in the parent node (where they came
// from as well). 
//(4) Incase the node is visited, we first check if it is the parent of the main node. 
//(5) If it is not the parent, then it means some other node visited it first and marked 
// it as one in the visited matrix. So we return true. 
//(6) Now we write this as a bool function. For connected components we need to run a for loop
// from the starting node to end node. If we detect any cycles in any one of the connected
// components then we return true. Or else we return false. 


//TC = O(N + 2E) where E is the number of edges. Refer BFS lecture to understand TC properly.
//SC = O(2N) one for visited array, other for the queue.