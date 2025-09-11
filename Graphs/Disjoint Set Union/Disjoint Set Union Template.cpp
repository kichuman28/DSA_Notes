#include<bits/stdc++.h>
using namespace std;

class DisjointSetUnion{
    vector<int> size;
    vector<int> parent;
    vector<int> rank;
    
    public:
        DisjointSetUnion(int n){
            rank.resize(n+1, 0);
            size.resize(n+1);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findParent(int node){
            if(parent[node] == node) return node;
            
            return parent[node] = findParent(parent[node]);
        }


        void unionByRank(int u, int v){
            int U = findParent(u);
            int V = findParent(v);
            
            if(U == V) return;
            
            if(rank[U] < rank[V]){
                parent[U] = V;
                rank[V]++;
            }else if(rank[V] < rank[U]){
                parent[V] = U;
                rank[U]++;
            }else{
                parent[V] = U;
                rank[U]++;                
            }
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

int main(){
    DisjointSetUnion ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    
    ds.unionByRank(3,7);
    
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
}






//Okay so the Disjoint Set Union algorithm is used to find out whether an element in a graph belongs to the same component 
//or not,in constant time. We can do it easily without constant time. So how do we do it in constant time? 
//Note to self: Watch video for better insights. Just writing down the main points here. 
//Maintain two vectors, one called parent and another called rank/size. 
//There are two functions coming at play here. One is to find the ultimate parent. Another is Union By Size or Union By Rank. 
//Union By Rank: Rank is more or less the height of the tree. Difficult to understand the intuition. 
//Union By Size: Size refers to the number of nodes in the tree. Way better to understand. 
//FindParent(): Not to find the parent just above the desired node, but to find it's boss. The parent at the top. 
//This function uses path compression, i.e if we find the ultimate parent of a node one time, we set it's parent as the boss node
//so that the next time we try to find the boss parent node of the same node it's easier. Like caching. Problem is the size will
//get distorted. So if we use Union By Size function it is easier to keep the size of the tree. 
//The whole purpose of this algorithm is to find whether a node belongs to a particular component at any stage of the graph, like
//dynamically changing graphs. Adding new edges between nodes, removing new edges etc. 
//In Union functoins, we always join the smaller tree with the bigger tree. This is because if we do it the other way then for a 
//node at the bottom for the bigger tree, it will need more time to get to the boss node, whereas if we do it the correct way then
//it won't take as much time as compared. The tiny differences add up. Watch video for more insight. 

//Code
//We need to make a class first. 
//Inside a constructor will be initialised for setting up the size of the parent array and the size array. 
//For size array, everything will be initialised to one, as in the beginning each component has itself as the size, i.e one. 
//For parent array, each element will have itself as the parent in the begninning.
//We need to use resize() function for the parent and size array to set everything. Can't use the normal way as it'll only 
//exist inside the constructor. We will be resizing it to size n+1 for 1 based indexing.
//Then for the FindParent function we recursively keep on going until the desired node == parent node, i.e we found the boss node.
//While returning we assign the boss node as the parent of the rest of the nodes, essentially doing path compression. 
//For the Union functions, we first find the ultimate parents of the two nodes we are trying to unionise. 
//If the parents are same, then we return nothing. Means they are part of the same component, already joined.
//A = ultimate parent of node A
//B = ultimate parent of node B
//If the size of parent A is less than parent B, (size[A] < size[B]) then we join parent A to parent B, i.e make A's 
//parent as B (parent[A] = B) and increase node B's size with the number of nodes in A (size[B] += size[A]).
//If B < A, then we do it the other way around. 
//If the size if same then we join any way we want and then increase the size accordingly. 
//The time complexity is 4 Alpha, where Alpha is a constant that's almost 1. No need to intuition behind it, very big derivation.