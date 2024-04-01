#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
public:
    // Function to return Breadth First Traversal of given graph.
    void dfs(int node, vector<int> adj[], int* visited, vector<int>&ls)
    {
        visited[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, ls);
            }
        }

    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        int* visited = new int[V] {0};
        int start = 0;
        vector<int>ls;
        dfs(start, adj, visited, ls);
        return ls;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector <int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Graph g;
    vector <int> ans = g.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}

-----------------------------------------------------------------------------------------------------------------------------  
Problem statement
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given 
using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.   

E is the number of edges present in graph G.
Note : The Graph may not be connected i.e there may exist multiple components in a graph.    

Sample Input 1:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2
0 1 2
3 4

void dfs(int start, vector<vector<int>>&adj,vector<int>&a, vector<int>&vis)
{
    vis[start]=1;
    a.push_back(start);
    for(auto it: adj[start])
    {
        if(vis[it]!= 1)
        {
            dfs(it, adj,a, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Adjacency Matrix to Adjacency list conversion
      vector<vector<int>> adj(V);
      for(int i=0; i<edges.size(); i++)
      {
             int u = edges[i][0];
             int v = edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
      }

       // Visited Array
       vector<int> vis(V,0);
       vector<vector<int>> ans;

      // Traversing
       for(int i=0; i<V; i++)
       { 
           if(vis[i]!=1)
           {
               vector<int> a;
               dfs(i,adj,a,vis);
               ans.push_back(a);
           }
       }
       return ans;
}      
