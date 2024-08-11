#include<iostream>
#include<vector>

using namespace std;

//queue
struct queue {
        int* node;
        int idx;
        int wt;
        int size;

    queue(int cap) : wt(cap),idx(0), size(0) {
        node= (int*)malloc(cap * sizeof(int));
    }

    ~queue() {
        free(node);
    }

    void push(int element) {
        if (size<wt) {
            int rearIndex= (idx + size) % wt;
            node[rearIndex]= element;
            size++;
        }
    }

    void pop() {
        if (size > 0) {
            idx= (idx + 1) % wt;
            size--;
        }
    }

    int front() const {
            return node[idx];
    }

    bool empty() const {
            return size == 0;
    }

    size_t getSize() const {
            return size;
    }
};

//input 
void inputg(int& N,int& M, int& K,vector<pair<int,int>>& req) {
    cin>>N>>M>>K;
    req.resize(M);
    for (int i= 0;i<M;++i) {
        cin>>req[i].first>>req[i].second;
    }
}

//graph
void gphmake(int N, int  M,const vector<pair<int,int>>& req,
                     vector<vector<int>>& adjList,vector<int>& idx) {
    adjList.resize(N + 1);
    idx.assign(N + 1,0);

    for (const auto& req : req) {
        int u= req.first;
        int v = req.second;
        adjList[u].push_back(v);
        idx[v]++;
    }
}

//topological sort
int topSort(int N,vector<vector<int>>& adjList,vector<int>& idx, int K) {
    queue q(N + 1);
    for (int i= 1;i<= N;++i) {
    if (idx[i] == 0)
            q.push(i);
    }

    int cyc= 0;
    while (!q.empty()) {
        int size= min(K,(int)q.getSize());
        for (int i= 0;i<size;++i) {
            int curr= q.front();
            q.pop();
            for (int v : adjList[curr]) {
                idx[v]--;
                if (idx[v] ==0)
                    q.push(v);
            }
        }
        cyc++;
    }

    return cyc;
}

int main() {
    int N,M,K;
    vector<pair<int,int>> req;
        inputg(N,M,K,req);
    vector<vector<int>> adjList;
    vector<int> idx;

    gphmake(N,M,req,adjList,idx);
    cout << topSort(N,adjList,idx,K) << endl;

    return 0;
}
