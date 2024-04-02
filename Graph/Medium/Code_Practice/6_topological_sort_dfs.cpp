Problem statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’,
vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. 
Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

Sample Input 1:
2
2 1
1 0
3 2
0 1
0 2
Sample Output 1:
1 0
0 2 1

#include <bits/stdc++.h> 
void dfs(int node, vector<int> adj[], int vis[], stack<int>&st)
{
    vis[node]=1;

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>adj[v];
    for(auto it:edges)
        adj[it[0]].push_back(it[1]);

    int vis[v]={0};
    stack<int>st;
    for(int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,st);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}	
