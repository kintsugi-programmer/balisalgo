#include <iostream>
#include <vector>
using namespace std;

// node
struct enode {
    int start,path,wt;
};


// disjoint sets

class disJointSets {
    int *parent,*rank;
    int n;

public:
    disJointSets(int n) {
        this->n= n;
    parent= new int[n + 1];
        rank= new int[n + 1];

        for(int i= 0; i <= n; i++) {
            rank[i]= 0;
            parent[i]= i;
        }
    }

    int find(int u) {
        if(u != parent[u]) {
            parent[u ]= find(parent[u]);
        }
        return parent[u];
    }

    void gmrg(int x,int y) {
    x= find(x),y= find(y);
        if(rank[x]> rank[y ]){parent[y]= x;}
        else {parent[x]= y;}
        if(rank[x ] == rank[y]){rank[y]++;}
    }

    ~disJointSets() {
        delete[] parent;
        delete[] rank;
    }
};


// graph  and krushals
class gph {
public:
    int V,E;
    vector<enode> enodes;

    gph(int v,int e) {
        V=v;
        E= e;
    }

    void addenode(int start,int path,int wt) {
    enode enode= {start,path,wt};
        enodes.push_back(enode);
    }

    int kruskalMST() {
        int cost= 0;
        sortenodes();

        disJointSets ds(V);

        for(auto& enode : enodes) {
            int u= enode.start;
            int v= enode.path;
            int set_u= ds.find(u);
            int set_v= ds.find(v);

        if(set_u!= set_v) {
                cost += enode.wt;
                ds.gmrg(set_u,set_v);
            }
        }

        return cost;
    }

private:
    void sortenodes() {
        for(int i= 0; i < E -1;i++) {
            for(int i2=0; i2< E- i - 1; i2++) {
            if(enodes[i2].wt> enodes[i2+1].wt) {
                    swap(enodes[i2],enodes[i2 +1]);
                }
            }
        }
    }
};


//graph 
gph make(const vector<vector<int>>& coor) {
    int n= coor.size();
    int num_enodes= n *(n -1)/ 2; 

    gph g(n,num_enodes);

    for(int i= 0; i < n; i++) {
    for(int i2= i + 1; i2 < n; i2++) {
        int wt= abs(coor[i][0] - coor[i2][0]) + abs(coor[i][1] - coor[i2][1]);
        g.addenode(i,i2,wt);
    }
    }

    return g;
}

int main() {
    vector<vector<int>> coor= {{0,0},{2,2},{3,10},{5,2},{7,0}};
    gph g= make(coor);
    cout << "Minimum fuel required : " << g.kruskalMST() << endl;
    return 0;
}
