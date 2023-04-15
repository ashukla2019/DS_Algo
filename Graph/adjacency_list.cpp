// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int vertex;
	list<int>*l;
	public:
		Graph(int v)
		{
			vertex = v;
			l = new list<int>[v];
		}
		void addEdge(int s, int d) 
		{
  			l[s].push_back(d);
  			l[d].push_back(s);
		}
		void deleteEdge(int s, int d)
		{
			l[s].remove(d);
			l[d].remove(s);
		}
		// Print the graph
		void printGraph() 
		{
  			for (int d = 0; d < vertex; ++d) 
  			{
    			cout << "\n Vertex "<< d << ":";
    			for (auto x : l[d])
    			{
      				cout << "-> " << x;
    				printf("\n");
  				}
			}
		}
		// dfs driver function.
		void dfs(int vertex) 
		{
			// If the current vertex is already visited, just return.
			if (visited[vertex] == true) return;

			cout << vertex << " ";

			// Mark the vertex as visited.
			visited[vertex] = true;
    
			// For every child of the current vertex, recursively call dfs();
			for (auto node: g[vertex]) {
			// node -> a child of vertex;
			dfs(node);
		}
};

int main() 
{
  int v = 5;
  Graph g(v);
  // Add edges
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.printGraph();
  cout<<"After deleting edge\n";
  g.deleteEdge(1, 2);
  g.printGraph();
}
