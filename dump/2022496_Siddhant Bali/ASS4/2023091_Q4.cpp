#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 7;

int dijkstra(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int, pair<int, int>>>> adj(n + 1);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], b = edge[2], a = edge[3];
        adj[u].emplace_back(v, make_pair(a, b));
        adj[v].emplace_back(u, make_pair(a, b));
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        int u_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u_dist > dist[u])
            continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int a = edge.second.first, b = edge.second.second;
            int min_travel_time = INF;
            for (int t = u_dist; t <= u_dist + 100; t++) {
                int travel_time = t + (a + t) / (t + 1) + b;
                min_travel_time = min(min_travel_time, travel_time);
            }
            if (min_travel_time < dist[v]) {
                dist[v] = min_travel_time;
                pq.emplace(min_travel_time, v);
            }
        }
    }

    return (dist[n] == INF) ? -1 : dist[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(4));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
    }

    cout << dijkstra(n, m, edges) << endl;
    return 0;
}