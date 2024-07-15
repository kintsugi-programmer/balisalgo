#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e) {
        V = v;
        E = e;
    }

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    int kruskalMST();
};

struct DisjointSets {
    int *parent, *rank;
    int n;

    DisjointSets(int n) {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        for (int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

int Graph::kruskalMST() {
    int minimumCost = 0;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSets ds(V);

    for (auto edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v) {
            minimumCost += edge.weight;
            ds.merge(set_u, set_v);
        }
    }

    return minimumCost;
}

int main() {
    vector<vector<int>> locations = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int n = locations.size();
    int num_edges = n * (n - 1) / 2; // Complete graph

    Graph g(n, num_edges);

    // Constructing the graph
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = abs(locations[i][0] - locations[j][0]) + abs(locations[i][1] - locations[j][1]);
            g.addEdge(i, j, weight);
        }
    }

    cout << "Minimum fuel required: " << g.kruskalMST() << endl;

    return 0;
}