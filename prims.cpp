#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> Pair;

// Function to implement Prim's Algorithm
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> key(V, INT_MAX);      // Minimum weight edge for each vertex
    vector<int> parent(V, -1);        // To store the MST
    vector<bool> inMST(V, false);     // To check if vertex is included in MST

    // Priority queue to select minimum weight edge in each iteration
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    // Start from the first vertex
    key[0] = 0;
    pq.push({0, 0}); // (key, vertex)

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Include vertex u in MST
        inMST[u] = true;

        // Traverse all vertices adjacent to u
        for (int v = 0; v < V; v++) {
            int weight = graph[u][v];

            // If v is not in MST and weight of (u, v) is smaller than current key of v
            if (weight && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, V);

    return 0;
}
