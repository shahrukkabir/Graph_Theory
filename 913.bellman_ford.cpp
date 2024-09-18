# include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;

const int mx = 1e5 + 123;
struct info {
    int u, v, w;
};
vector<info> e;
ll dist[mx];

bool bellmanFord(int s, int n, int m) {
    for (int i = 1; i <= n; i++) dist[i] = LONG_MAX;
    dist[s] = 0;
    bool isCycle = false;
    for (int i = 1; i <= n; i++) {              // n -1 times ...... if in nth times relax that mean there is a cycle    
        isCycle = false;                        
        for (int j = 0; j < m; j++) {
            int u = e[j].u;                                                              
            int v = e[j].v;
            int w = e[j].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;        //dist[v] = max(-LONG_MAX, dist[u] + w);
                isCycle = true;
            }
        }
    }
    return isCycle;
}

int main() {
    FAST

    int t; cin >> t;
    while (t--) {
        e.clear(); 
        int n, m; cin >> n >> m;
        while (m--) {
            int u, v, w; cin >> u >> v >> w;
            e.push_back({u, v, w});
        }
        if (bellmanFord(0, n, m)) {
            cout << "possible" << nl;
        } else {
            cout << "not possible" << nl;
        }
    }

    return 0;
}


// highest n-1 bar loop solar por jekono graph(cycle takok ba na takok) er shortest path bahir hoi jabe 
// n tomo bare jodi shortest path update hoi that means cycle ase tai update hosse