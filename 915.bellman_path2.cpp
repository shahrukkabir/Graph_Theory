//https://cses.fi/problemset/task/1197/

#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;
 
class triplet{
public:
	ll u,v,w;
};
 
const int mx=1e5+1233; 
ll n, m;	
vector<triplet> edges;
ll dist[mx];
ll par[mx];
 
void bellman_ford()
{	 
	ll x;
	for(ll i = 1; i <= n; i++)
	{
		x = -1;
		for(auto e: edges)
		{
 
			ll u = e.u;
			ll v = e.v;
			ll w = e.w;
			if(dist[u]+w < dist[v])
			{
				dist[v] = w+dist[u];
				par[v] = u;
				x = v;
			}
		}
	} 
 
	if(x == -1)
		cout << "NO" << endl;
 
	else
	{
		for(ll i = 1; i <= n; i++)
		{
			x = par[x];
		}
 
		vector<ll> cycle;
 
		for(ll v = x; ; v = par[v])
		{
			cycle.push_back(v);
			if(v == x and cycle.size() > 1)
				break;
		}
 
		reverse(cycle.begin(), cycle.end());
 
		cout << "YES" << endl;
		for(auto v: cycle)
		{
			cout << v << " ";
		}
 
		cout << endl;
	}
 
 
}
 
 
int main()
{
	FAST

	cin >> n >> m;

    while(m--){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
	  
	bellman_ford();	
}