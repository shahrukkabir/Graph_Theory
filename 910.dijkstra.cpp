#include <bits/stdc++.h>
using namespace std;

#define    FAST            ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define    nl              '\n'
#define    F               first
#define    S               second
typedef    long long       ll;
typedef    vector<ll>      vll;
typedef    pair<ll, ll>    pll;
typedef    vector<pll>     vpl;                       //T.C : O((V+E)logV
const      int             mx = 1e5+123;


vector<pll> adj[mx];                                  //vector<vll>adj[mx];    //adj[0]= [{2,3},{1,5},{5,2}]  ->adj list of node 0      
ll dist[mx];

void dijkstra(int s, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = LONG_MAX;                           //initialization
    }
    dist[s] = 0;                                      // initializing source distance   

    priority_queue<pll, vpl, greater<pll>> pq;        // sort small to big     //   priority_queue<vll,vector<vll>,greater<vll>>pq;
    pq.push({0, s});                                  // {dist, node}
    while (!pq.empty()) {
        ll currD = pq.top().F;                        // currD -> dist
        int u = pq.top().S;                           // u -> node
        pq.pop();
        if (currD > dist[u]) {                        // dis[u] -> previous distance
            continue;                                 // Skip if this node has been processed with a shorter distance
        }
        for (auto p : adj[u]) {                       // p -> {node, cost}
            int v = p.F;                              // v -> node 
            ll  w = p.S;                              // w -> cost
            if (dist[v]>currD+w) {                    // currD + w -> go to node v
                dist[v] = currD + w;                  // relaxation
                pq.push({dist[v], v});
            } 
        }
    }
}

int main() {
    FAST

    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(0, n);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << nl;

    return 0;
}


/* 
        5 7
        1 3 3
        1 2 2
        1 4 6
        2 0 6
        2 3 7
        0 4 3
        3 4 5

        0 8 6 8 3 

*/

// For 1 based indexing 

#include <bits/stdc++.h>
using namespace std;

#define    FAST            ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define    nl              '\n'
#define    F               first
#define    S               second
typedef    long long       ll;
typedef    vector<ll>      vll;
typedef    pair<ll, ll>    pll;
typedef    vector<pll>     vpl;                       //T.C : O((V+E)logV
const      int             mx = 1e5+123;


vector<pll> adj[mx];                                  // adjacency list of nodes
ll dist[mx];

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = LONG_MAX;                           // initialize distances
    }
    dist[s] = 0;                                      // source distance is 0

    priority_queue<pll, vpl, greater<pll>> pq;        // min-heap (sort small to big)
    pq.push({0, s});                                  // {dist, node}
    while (!pq.empty()) {
        ll currD = pq.top().F;                        // currD -> current distance
        int u = pq.top().S;                           // u -> current node
        pq.pop();
        if (currD > dist[u]) {                        // skip if this node has been processed with a shorter distance
            continue;
        }
        for (auto p : adj[u]) {                       // iterate over neighbors of u
            int v = p.F;                              // v -> neighbor node
            ll  w = p.S;                              // w -> weight of the edge
            if (dist[v] > currD + w) {                // relaxation step
                dist[v] = currD + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    FAST

    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1, n); // start Dijkstra from node 1
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << nl;

    return 0;
}
