#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int adjMatrix[100][100];
    int adjList[100][100];
    int adjListSize[100];

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            adjListSize[i] = 0;
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
                adjList[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u][v] = 1;
        adjList[u][adjListSize[u]++] = v;
        
        if (!directed) {
            adjMatrix[v][u] = 1;
            adjList[v][adjListSize[v]++] = u;
        }
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        cout << "  ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayList() {
        cout << "\nAdjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adjListSize[i]; j++) {
                cout << adjList[i][j];
                if (j < adjListSize[i] - 1) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    int inDegree(int v, bool directed) {
        if (!directed) {
            return adjListSize[v];
        }
        
        int count = 0;
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[i][v] == 1) {
                count++;
            }
        }
        return count;
    }

    int outDegree(int v) {
        return adjListSize[v];
    }

    int degree(int v) {
        return adjListSize[v];
    }

    void displayAdjacentVertices(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for (int i = 0; i < adjListSize[v]; i++) {
            cout << adjList[v][i];
            if (i < adjListSize[v] - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    int countEdges(bool directed) {
        int count = 0;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    count++;
                }
            }
        }
        return directed ? count : count / 2;
    }
};

int main() {
    int vertices, edges, choice;
    bool directed;
    
    cout << "Enter number of vertices: ";
    cin >> vertices;
    
    Graph g(vertices);
    
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;
    
    cout << "Enter number of edges: ";
    cin >> edges;
    
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, directed);
    }
    
    while (true) {
        cout << "\n=== Graph Operations ===" << endl;
        cout << "1. Display Adjacency Matrix" << endl;
        cout << "2. Display Adjacency List" << endl;
        cout << "3. Get In-Degree of a vertex" << endl;
        cout << "4. Get Out-Degree of a vertex" << endl;
        cout << "5. Get Degree of a vertex" << endl;
        cout << "6. Display Adjacent Vertices" << endl;
        cout << "7. Count Total Edges" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        int vertex;
        
        switch (choice) {
            case 1:
                g.displayMatrix();
                break;
            case 2:
                g.displayList();
                break;
            case 3:
                cout << "Enter vertex: ";
                cin >> vertex;
                cout << "In-Degree of vertex " << vertex << ": " << g.inDegree(vertex, directed) << endl;
                break;
            case 4:
                cout << "Enter vertex: ";
                cin >> vertex;
                cout << "Out-Degree of vertex " << vertex << ": " << g.outDegree(vertex) << endl;
                break;
            case 5:
                cout << "Enter vertex: ";
                cin >> vertex;
                cout << "Degree of vertex " << vertex << ": " << g.degree(vertex) << endl;
                break;
            case 6:
                cout << "Enter vertex: ";
                cin >> vertex;
                g.displayAdjacentVertices(vertex);
                break;
            case 7:
                cout << "Total number of edges: " << g.countEdges(directed) << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
