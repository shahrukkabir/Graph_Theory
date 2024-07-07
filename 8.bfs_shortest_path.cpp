#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;

const int mx = 1e5 + 123;
vector<int> adj[mx];
int lev[mx];
int par[mx];

void bfs(int s) {
    memset(lev, -1, sizeof(lev));
    memset(par, -1, sizeof(par));
    queue<int> q;
    q.push(s);
    lev[s] = 0;                          //single source  shortest path using bfs 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (lev[v] == -1) {
                lev[v] = lev[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    FAST

    int n, e; 
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s,t; cin>>s>>t;
    bfs(s);

    if (lev[t] == -1) {
        cout << "No route" << nl;
        return 0;
    } 
    
    par[s] = -1;

    vector<int> path; 

    while( t!=-1 ){
        path.push_back(t);
        t = par[t];
    }

    reverse(path.begin(),path.end());

    for( auto u : path ){
        cout<<u<<" ";
    }
    cout<<nl;

    return 0;
}
