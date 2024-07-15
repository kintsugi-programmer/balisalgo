#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    bool directed; // Directed or undirected
    vector<vector<int>> adjList;
    vector<vector<bool>> adjMatrix;

public:
    // Constructor
    Graph(int vertices, bool isDirected) : V(vertices), directed(isDirected) {
        adjList.resize(V);
        adjMatrix.resize(V, vector<bool>(V, false));
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjMatrix[u][v] = true;
        if (!directed) {
            adjList[v].push_back(u); // If undirected, add edge in both directions
            adjMatrix[v][u] = true;
        }
    }

    // Function to remove an edge from the graph
    void removeEdge(int u, int v) {
        auto it = find(adjList[u].begin(), adjList[u].end(), v);
        if (it != adjList[u].end()) {
            adjList[u].erase(it);
            adjMatrix[u][v] = false;
        }
        if (!directed) {
            it = find(adjList[v].begin(), adjList[v].end(), u);
            if (it != adjList[v].end()) {
                adjList[v].erase(it);
                adjMatrix[v][u] = false;
            }
        }
    }

    // Depth-first search (DFS) algorithm
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adjList[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    // Breadth-first search (BFS) algorithm
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adjList[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }

    // Function to check if the graph is connected
    bool isConnected() {
        vector<bool> visited(V, false);
        DFSUtil(0, visited);

        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }

    // Function to check if the graph is directed or undirected
    bool isDirected() {
        return directed;
    }

    // Function to check if the graph has any cycles (uses DFS)
    bool hasCycle() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; ++i) {
            if (hasCycleUtil(i, visited, recStack)) {
                return true;
            }
        }
        return false;
    }

    bool hasCycleUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        if (!visited[v]) {
            visited[v] = true;
            recStack[v] = true;

            for (int u : adjList[v]) {
                if (!visited[u] && hasCycleUtil(u, visited, recStack)) {
                    return true;
                } else if (recStack[u]) {
                    return true;
                }
            }
        }
        recStack[v] = false; // Remove the vertex from recursion stack
        return false;
    }

    // Function to perform topological sorting of the graph (if directed)
    void topologicalSort() {
        if (!directed) {
            cout << "Topological sort is not applicable for undirected graphs." << endl;
            return;
        }

        vector<int> inDegree(V, 0);

        // Count in-degree of each vertex
        for (int v = 0; v < V; ++v) {
            for (int u : adjList[v]) {
                inDegree[u]++;
            }
        }

        queue<int> q;

        // Enqueue vertices with in-degree 0
        for (int v = 0; v < V; ++v) {
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }

        // Perform topological sorting
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adjList[v]) {
                if (--inDegree[u] == 0) {
                    q.push(u);
                }
            }
        }
    }
};

int main() {
    // Test the implementation
    Graph graph(6, false); // Undirected graph with 6 vertices

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    cout << "Depth First Search (DFS): ";
    graph.DFS(0);
    cout << endl;

    cout << "Breadth First Search (BFS): ";
    graph.BFS(0);
    cout << endl;

    cout << "Is the graph connected? " << (graph.isConnected() ? "Yes" : "No") << endl;
    cout << "Is the graph directed? " << (graph.isDirected() ? "Yes" : "No") << endl;

    // Test for directed graph
    Graph directedGraph(5, true); // Directed graph with 5 vertices
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 2);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 4);
    directedGraph.addEdge(4, 1); // Adding a cycle

    cout << "Does the directed graph have a cycle? " << (directedGraph.hasCycle() ? "Yes" : "No") << endl;
    cout << "Topological Sort of the directed graph: ";
    directedGraph.topologicalSort();
    cout << endl;

    return 0;
}
