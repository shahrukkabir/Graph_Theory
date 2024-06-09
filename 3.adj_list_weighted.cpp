#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
vector<pair<int, int>> adj[mx];

int main()
{
    int n, m;
    cin >> n >> m;

    for ( int i = 1; i <= m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back ( {v, w} );
        adj[v].push_back ( {u, w} ); /// remove this line for directed graph
    }

    for ( int i = 1; i <= n; i++ ) {
        cout << "Adjacent nodes of node " << i << " : \n";
        for ( auto u : adj[i] ) {
            cout << "Node : " << u.first << " " << "Weight : " << u.second << endl;
        }
        cout << endl << endl;
    }

 
    return 0;
}

Adjacent nodes of node 1 : 
Node : 2 Weight : 10
Node : 2 Weight : 13
Node : 2 Weight : 14


Adjacent nodes of node 2 : 
Node : 1 Weight : 10
Node : 1 Weight : 13
Node : 1 Weight : 14
Node : 3 Weight : 2
Node : 4 Weight : 3


Adjacent nodes of node 3 : 
Node : 2 Weight : 2


Adjacent nodes of node 4 : 
Node : 2 Weight : 3