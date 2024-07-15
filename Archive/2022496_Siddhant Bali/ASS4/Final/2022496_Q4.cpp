#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF=1e9 + 7;

//graph func
void addEdge(vector<vector<pair<int,pair<int,int>>>>& ADJ,int u,int v,int a,int b) {
    ADJ[u].emplace_back(v,make_pair(a,b));
    ADJ[v].emplace_back(u,make_pair(a,b));
}

//graph 
vector<vector<pair<int,pair<int,int>>>> makegph(int n,const vector<vector<int>>& edges) {
    vector<vector<pair<int,pair<int,int>>>> ADJ(n + 1);
    for (const auto& edge : edges) {
        int u=edge[0],v=edge[1],b=edge[2],a=edge[3];
        addEdge(ADJ,u,v,a,b);
    }
    return ADJ;
}




// traversal time
int Travtime(int a,int b,int t) {
    return t + (a + t) / (t + 1) + b;
}

//minimumm traversal time limit cal 
int mintime(int a,int b,int u_dist) {
    int min_travel_time=INF;
    for (int t=u_dist; t <= u_dist + 100; t++) {
        int travel_time=Travtime(a,b,t);
        min_travel_time=min(min_travel_time,travel_time);
    }
    return min_travel_time;
}

// edge and distance
int travmin(int a,int b,int u_dist) {
    return mintime(a,b,u_dist);
}

//dikastras algo
int dijkstra(int n,int m,const vector<vector<int>>& edges) {
    vector<vector<pair<int,pair<int,int>>>> ADJ=makegph(n,edges);

    vector<int> dist(n + 1,INF);
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.emplace(0,1);

    while (!pq.empty()) {
    int u_dist=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if (u_dist > dist[u])
            continue;

        for (const auto& edge : ADJ[u]) {
            int v=edge.first;
            int a=edge.second.first,b=edge.second.second;
            int min_travel_time=travmin(a,b,u_dist);
            if (min_travel_time < dist[v]) {
                dist[v]=min_travel_time;
                pq.emplace(min_travel_time,v);
        
            }
        }
    }

    return (dist[n] == INF) ? -1 : dist[n];
}


//driver code
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(4));
    for (int i=0; i < m; i++) {cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];}
    cout<<dijkstra(n,m,edges)<<endl;
    return 0;
}