Problem statement
Given a graph, check whether the graph is bipartite or not. Your function should return true if the given graph's vertices
can be divided into two independent sets, ‘U’ and ‘V’ such that every edge (‘u’, ‘v’) either connects a vertex from ‘U’ to ‘V’
or a vertex from ‘V’ to ‘U’.

You are given a 2D array ‘edges’ which contains 0 and 1, where ‘edges[i][j]’ = 1 denotes a bi-directional edge from ‘i’ to ‘j’.
Note:
If edges[i][j] = 1, that implies there is a bi-directional edge between ‘i’ and ‘j’, that means there exists both edges from
‘i’ to ‘j’ and to ‘j’ to ‘i’.
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
bool check(int start, vector<int>adj[], int color[])
{
	queue<int>q;
	q.push(start);
	color[start] = 0;

	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		for(auto adjnode:adj[n])
		{
			if(color[adjnode] == -1)
			{
				color[adjnode] = !color[n];
				q.push(adjnode);
			}
			else if(color[adjnode] == color[n])
			    return false;
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int V = edges.size();
	vector<int> adj[V];
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			if(edges[i][j] == 1 && i != j)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	int color[V];
	for(int i = 0; i < V; i++)  color[i]=-1;

	for(int i = 0; i < V; i++)
	{
		if(color[i] == -1)
		{
			if(check(i,adj,color) == false)
			    return false;
		}
	}
	return true;
}
