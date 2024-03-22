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
