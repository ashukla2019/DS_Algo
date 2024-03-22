#include <bits/stdc++.h>
using namespace std;

/*Steps:
1) Create visit array and initialize all elements with 0;
2) Create queue of int to add vertex value.
3) Insert first node to queue and iterate queue until it becomes empty
4) pop the front node from queue and push to vector
5) Now check the neighbours of node and mark them visited if not visited earlier
6) Push the neighbours to queue now
*/       

-------------------------------------------------------------------------

// Function to return Breadth First Traversal of given graph.
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int *vis = new int[V]{ 0 };
        vis[0] = 1;
        queue<int> q;
        // push the initial starting node 
        q.push(0);
        vector<int> bfs;
        // iterate till the queue is empty 
        while (!q.empty()) {
            // get the topmost element in the queue 
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            // traverse for all its neighbours 
            for (auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
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
    vector <int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Graph g;
    vector <int> ans = g.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
