#include <iostream>
using namespace std;

struct Edge {
    int u, v, weight;
};

void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int findParent(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal(Edge edges[], int V, int E) {
    sortEdges(edges, E);

    int parent[100];
    int rank[100];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "\nKruskal's Minimum Spanning Tree:" << endl;
    int mstWeight = 0;
    int edgeCount = 0;

    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        if (uParent != vParent) {
            cout << u << " - " << v << " : " << weight << endl;
            mstWeight += weight;
            unionSets(parent, rank, uParent, vParent);
            edgeCount++;
        }
    }

    cout << "Total Weight of MST: " << mstWeight << endl;
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100];

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(edges, V, E);

    return 0;
}
