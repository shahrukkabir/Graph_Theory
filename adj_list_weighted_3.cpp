#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
vector<pair<int, int>> adj[mx];  //array of vectors of pairs

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

/* 


adj[1]=[{2,10},{2,13},{2,14}]
adj[2]=[{1,10},{1,13},{1,14},{3,2},{4,3}]
adj[3]=[{2,2}]
adj[4]=[{2,3}]



*/