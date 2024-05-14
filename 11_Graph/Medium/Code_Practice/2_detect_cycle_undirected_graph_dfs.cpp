bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
-------------------------------------------------------------------------------------------------------------------  
Problem:
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
Note:
1. There are no parallel edges between two vertices.
2. There are no self-loops(an edge connecting the vertex to itself) in the graph.
3. The graph can be disconnected.
For Example :
Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int>&visited)
{
    visited[node] = 1;
           
    for(auto nodes: adj[node])
    {
        //if node is already visited and node is not parent => we got cycle, return true.    
        if(nodes != parent && visited[nodes])
        {
            return true;
        }
        //if node is not already visited but if it returns true=> we got cycle, return true.        
        else if(!visited[nodes])
            if(dfs(nodes, node, adj, visited)==true)
                return true;
       
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>visited(n+1, 0);
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v), adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1, adj, visited))  
                return "Yes";
        }
    }

    return "No";
}
