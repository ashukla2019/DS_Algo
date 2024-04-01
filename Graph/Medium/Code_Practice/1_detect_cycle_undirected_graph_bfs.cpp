The algorithm steps are as follows:
For BFS traversal, we need a queue data structure and a visited array. 
Push the pair of the source node and its parent data (<source, parent>) in the queue, and mark the node as visited. The parent will be needed so that we don’t do a backward traversal in the graph, we just move frontwards. 
Start the BFS traversal, pop out an element from the queue every time and travel to all its unvisited neighbors using an adjacency list.
Repeat the steps either until the queue becomes empty, or a node appears to be already visited which is not the parent, even though we traveled in different directions during the traversal, indicating there is a cycle.
If the queue becomes empty and no such node is found then there is no cycle in the graph.
-----------------------------------------------------------------------------------
bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
---------------------------------------------------------------------------------------------------------------
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

bool bfs(int node, vector<int> adj[], vector<int>&visited)
{
    queue<pair<int, int>> q; 
    q.push({node, -1}); 
    visited[node] = 1;
    while(!q.empty())
    {
        
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto nodes: adj[node])
            {
                if(nodes != parent && visited[nodes])
                {
                    return true;
                }
                if(nodes == parent)    continue;
                q.push({nodes, node});
                visited[nodes] = 1;
            }
       
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
            if(bfs(i, adj, visited))  
                return "Yes";
        }
    }

    return "No";
}      
