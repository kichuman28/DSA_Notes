
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        //Step 1: Create the queue. You don't need pq as it is already storing in a sorted order coz of BFS
        queue<pair<int, int>> q;
        q.push({start, 1}); //Push the src node and the steps taken to reach the end node
        
        //Step 2: Create a dist array of size(100000) with INT_MAX. Set the start node's 
        //distance as 0.
        vector<int> dist(100000,INT_MAX);
        dist[start] = 0;
        
        //Step 3: Traverse the queue, update the dist array, return the no. of steps if 
        //matched with end node.
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            //Next I have to push the adjacent nodes which is the start node multiplied
            //by each element in the arr.
            for(int i = 0; i < arr.size(); i++){
                int v = (node * arr[i]) % 100000; //Incase the node exceeds 100000
                if(steps < dist[v]){
                    dist[v] = steps;
                    q.push({v, steps + 1});
                }
            }
        }
        
        if(dist[end] == INT_MAX) return -1;
        return dist[end];
    }
};



//Approach
//I almost got the answer.
//The first step is making the graph. BUt the doubt is when to stop making it becuase there's
//no end to it. It's impossible to come up with a condition to make the graph to traverse it.
//Try it yourself, you cant.
//So what we do is we first make a queue with a pair that represents each number as node and 
//the second one represents the steps it is taking to reach the end node
//So we don't make the graph. Instead we start from the src node along with the number of steps
//Then we add it to the queue. Next we multiply each element in the arr with the src node
//update the steps by 1. 
//A dist array is created of size 9999 which is used to represent the steps taken from src
//node to each one of the nodes in the array. 
//Each time we add to the queue we also update the dist array by checking is the steps is less
//than what it contains now. Similar to dijkstra's model. If is, we update and push the new
//node and steps into the queue.
//Once the queue is empty, we check if the end node's value in the dist array is equal to
//INT_MAX or not.
//If yes it signifies it is impossible to reach that node, we return -1.
//Else we return the answer, which lies in the value of dist[end].

//CHeck the image to understand why we use mod 100000
//If the number exceeds 100000 then the ANSWER IS number%100000. So WE HAVE TO DO this regardless.