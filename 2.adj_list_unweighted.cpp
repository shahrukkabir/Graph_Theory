#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
vector<int> adj[mx];   //array of vector

int main()
{
    int n, m;           //n>node,m->edge
    cin >> n >> m;

    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back ( v );
        adj[v].push_back ( u );       // remove this line for directed graph
    }

    for ( int i = 1; i <= n; i++ ) {
        cout << "Adjacent nodes of node " << i << " : ";
        for ( auto u : adj[i] ) {
            cout << u << " ";
        }
        cout << endl;
    }


    return 0;
}