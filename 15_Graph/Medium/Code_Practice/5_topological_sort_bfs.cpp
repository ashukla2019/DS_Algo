A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’,
vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. 
Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    // Write your code here
    vector<int> adj[v];

    for(int i=0;i<e;i++)
	{
        adj[edges[i][0]].push_back(edges[i][1]); //directed graph
    }

    vector<int> inDegree(v,0);
    //Find the indegree of all vertices
    for(int i=0;i<v;i++)
	{
        for(auto it:adj[i])
		{
            inDegree[it]++;
        }
    }

    queue<int> q;

    // Push all the vertices with indegree 0 to queue
    for(int i=0;i<v;i++)
	{
        if(inDegree[i]==0)
		{
            q.push(i);
        }
    }
    vector<int> topo;

    // Normal bfs traversal
    while(!q.empty())
	{
        int f = q.front();
        q.pop();
        topo.push_back(f);

        // For all the adjecent nodes of the cur node
        for(auto it:adj[f])
		{
            //Each adjecent node will get visited hence decrease the indegree value.
            inDegree[it]--;
            if(inDegree[it]==0)
			{
                // Once indegree becomes zero push that node to queue.
                q.push(it);
            }
        }
    }

    return topo;
}	
