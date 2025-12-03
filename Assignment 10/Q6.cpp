#include <iostream>
#include <climits>
using namespace std;

int findMinDistance(int dist[], bool visited[], int V) {
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(int adj[100][100], int V, int src) {
    int dist[100];
    bool visited[100];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex " << src << ":" << endl;
    cout << "Vertex\t\tDistance" << endl;

    for (int i = 0; i < V; i++) {
        cout << i << "\t\t";
        if (dist[i] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
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

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u][v] = weight;
        adj[v][u] = weight;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(adj, V, src);

    return 0;
}
