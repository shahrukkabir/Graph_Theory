//Connected Components in a Graph: https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'

const int mx = 123;

bool vis[mx];
vector<int> adj[mx];

void dfs(int u) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    FAST
    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << nl;
    
    return 0;
}


//Maximum component size 

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'

const int mx = 123;

bool vis[mx];
vector<int> adj[mx];
int component_size;

void dfs(int u) {
    vis[u] = true;
    component_size++;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    FAST
    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int max_component_size = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            component_size = 0;
            dfs(i);
            max_component_size = max(max_component_size, component_size);
        }
    }
    cout << max_component_size << nl;
    
    return 0;
}
