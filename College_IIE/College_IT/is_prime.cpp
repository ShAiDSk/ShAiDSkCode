#include<bits/stdc++.h>
using namespace std;

struct edge{
    int v, u, w;
    bool operator < (edge const &other){
        return w < other.w;
    }
};

int main(){
    int n; cin >> n;
    vector <edge> edges;
    int cost = 0;
    vector <int> tree_id(n);
    vector <edge> result;
    for (int i = 1; i <= n; i++){
        tree_id[i] = i;
    }
    sort()

    for (int i = 0; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        edges[u].pb({w, v});
        edges[v].pb({w, u});
    }
    dfs();
}