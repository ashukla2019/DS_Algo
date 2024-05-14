Problem:
Given a graph, check whether the graph is bipartite or not. Your function should return true if the given graph's vertices 
can be divided into two independent sets, ‘U’ and ‘V’ such that every edge (‘u’, ‘v’) either connects a vertex from ‘U’ to ‘V’
or a vertex from ‘V’ to ‘U’.

You are given a 2D array ‘edges’ which contains 0 and 1, where ‘edges[i][j]’ = 1 denotes a bi-directional edge from ‘i’ to ‘j’.
Note:
If edges[i][j] = 1, that implies there is a bi-directional edge between ‘i’ and ‘j’, that means there exists both edges from ‘i’ to ‘j’ and to ‘j’ to ‘i’.
For example
Given:
‘N’ = 3
‘edges’ = [[0, 1, 1], [0, 0, 1], [0,0,0]]. 

Sample Input 1 :
2
4
0 1 0 0 
0 0 0 1 
0 0 0 0 
0 0 0 0 
3
0 1 1
0 0 1
0 0 0
Sample Output 1 :
1
0 

#include <bits/stdc++.h>
bool dfs(int node, int col, int color[], vector<int>adj[])
{
	color[node]=col;
	for(auto it : adj[node])
	{
		if(color[it]==-1)
		{
			if(dfs(it, !col, color, adj)==false) 
				return false;
		}
		else if(color[it]==col){
			return false;
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) 
{
	//convert adjacency matrix to adjcency list

	int V= edges.size();
	vector<int> adj[V];

	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(edges[i][j]==1 && i!=j)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int color[V]; 
	for(int i=0;i<V;i++) color[i]=-1; 

	for(int i=0;i<V;i++)
	{
		if(color[i] == -1)
		{
			if(dfs(i, 0, color, adj)== false) 
				return false;
		}
	}
	return true;
}	
	
