#include <iostream>
#include <climits>
using namespace std;

int findMinKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void prim(int adj[100][100], int V) {
    int parent[100];
    int key[100];
    bool mstSet[100];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    cout << "\nPrim's Minimum Spanning Tree:" << endl;
    int totalWeight = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }

    cout << "Total Weight of MST: " << totalWeight << endl;
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

    prim(adj, V);

    return 0;
}
