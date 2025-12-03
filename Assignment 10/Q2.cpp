#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        int x = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return x;
    }
};

void bfs(int start, int adj[100][100], int V) {
    bool visited[100];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    Queue q;
    visited[start] = true;
    q.enqueue(start);

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (!q.isEmpty()) {
        int u = q.dequeue();
        cout << u << " ";

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.enqueue(v);
            }
        }
    }
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
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    bfs(start, adj, V);

    return 0;
}
