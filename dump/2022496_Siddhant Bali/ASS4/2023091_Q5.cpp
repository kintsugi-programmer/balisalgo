#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minBrewingCycles(int N, int M, int K, vector<pair<int, int>>& requirements) {
    vector<int> inDegree(N + 1, 0);
    vector<vector<int>> adjList(N + 1);

    for (auto& req : requirements) {
        int u = req.first;
        int v = req.second;
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    int brewingCycles = 0;
    while (!q.empty()) {
        int size = min(K, (int)q.size());
        for (int i = 0; i < size; ++i) {
            int curr = q.front();
            q.pop();
            for (int v : adjList[curr]) {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }
        brewingCycles++;
    }

    return brewingCycles;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> requirements(M);
    for (int i = 0; i < M; ++i) {
        cin >> requirements[i].first >> requirements[i].second;
    }

    cout << minBrewingCycles(N, M, K, requirements) << endl;

    return 0;
}
