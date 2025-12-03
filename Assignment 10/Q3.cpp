#include <iostream>
using namespace std;

void dfsUtil(int u, int adj[100][100], bool visited[], int V) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfsUtil(v, adj, visited, V);
        }
    }
}

void dfs(int start, int adj[100][100], int V) {
    bool visited[100];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    cout << "DFS Traversal starting from vertex " << start << ": ";
    dfsUtil(start, adj, visited, V);
    cout << endl;
}

int main() {
    int V, E;
    int adj[100][100];

    cout << "Enter number of vertices: ";
    cin >> V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    dfs(start, adj, V);

    return 0;
}
