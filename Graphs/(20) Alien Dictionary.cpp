class Solution {
    
  private:
    vector<int> topoSort(vector<int> adj[], int n){
        // int n = adj.size();
        queue<int> q;
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        
        return topo;
    }
    
    
    
  public:
    string findOrder(string dict[], int n, int k) {
        
        vector<int>adj[k];
        
        for(int i = 0; i < n - 1; i++){
            string str1 = dict[i];
            string str2 = dict[i + 1];
            int len = min(str1.size(), str2.size());
            for(int ptr = 0; ptr < len; ptr++){
                if(str1[ptr] != str2[ptr]){
                    adj[str1[ptr] - 'a'].push_back(str2[ptr] - 'a'); //Here if str1[ptr] is b then it's ascii value is 66. 'a' ascii value is 65. So if we subtract 65 from 66 we get 1. Similarly for a we get 0, b we get 1, c we get 2, d we get 3 and so on. The numbers now represent the characters as nodes.
                    break;
                }
            }
        }
        
        
        vector<int> ans;
        ans = topoSort(adj, k);
        
        string str = "";
        for(auto it : ans){
            str += char(it + 'a'); //Here if 'it' is 1 and we add ascii value of a(65) we get 66. Then when we do char(66), we get b. This is true for all the nodes.
        }
        
        return str;
    }
};


//Approach
// So according to the question, the aliens have a different language than ours. The only thing
// that differs is the ordering of the alphabets. K refers to the number of alphabets. So what we
// have to do is we should return the correct ordering of the alphabets. If we look at the first
// example, [b,d,c,a] is the order according to the letters given in the dictionary. How we know
// this? 
// - baa | abcd : b and a is the first set of letters that's different, so b comes before a
// - abcd | abca : the fourth letters, d and a are different, i.e d comes before a
// - abca | cab : the first letters, a & c are different, i.e a comes before c.
// - cab | cad : the last letters, b & d are different, i.e b comes before d.

// So from these observations, we can write the order as [b,d,a,c].

// Now what we need to do is turn these observations to code. 

// 1) We have to compare each string in dict by storing it in str1 & str2 and compare it.
// 2) Then we have to disect each string and compare each letter. For this we run a pointer loop.
// The size should be the length of the smallest string from str1 & str2. Why? Common sense bro
// 3) When we find the first letter that's different, we make a graph using two vectors & push_back
// method and break since we don't need to find any other differences. Note that we are dealing with
// characters, we need to convert them to numbers (refer code) and back to characters to return 
// as a string(refer code). The graph will become a directed graph. Acyclic or cyclic, depends
// on the question. If no cycle exists then it means there's a valid ordering and the output is 1
// If cycle exists then it means there's no valid ordering and the output is 0.
// 4) Now we have the graph of alphabets that's converted to the numbers. Now since we need the
// ordering of something before something, only TOPO Sort comes to mind.
// 5) Do the topo sort and we will get the ordering. Convert that ordering back to alphabets.
// (Refer code on how to do it). 
// 6) Now we return that string from the ordering. If it is valid or not, the driver code will
// handle it.  