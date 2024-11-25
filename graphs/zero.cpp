// ---------------------Using Adjacency Matrix--------------------------

#include<iostream>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;

    int adj[n+1][m+1]; // If this is a 1-based indexing, if zero u can take n and m
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    
    }
    return 0;
}

// Space Complexity = O(n^2)

// ---------------------Using Adjacency list--------------------------

#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[n+1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // If it is a directed graph then we dont require the below line , so there's simply an edge from u to v. [u --> v]
        // Space Complexity = O(Edges)
        adj[v].push_back(u);
    }

    return 0;
}

// Space Complexity = O(2*n)

// For the weighted graph, you have to store the weight of edge in the adjacency matrix rather than 1.
// But in adjacency list , you have to store the list in pairs, with <node, weight>