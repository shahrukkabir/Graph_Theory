////https://cses.fi/problemset/task/1197/

#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;

const ll mx = 2513;
struct info{
    ll u,v,w;
};
vector<info>e;
ll dist[mx];
ll par[mx];

vector<ll> bellmanPath(ll s, ll n, ll m){

    vector<ll>path;
    // for(ll i=1;i<=n;i++) dist[i]=LLONG_MAX;
    // dist[s]=0;
    ll x = -1;
    for(ll i=1;i<=n;i++){
        x=-1;
        for(ll j=0;j<m;j++){
            ll u = e[j].u;
            ll v = e[j].v;
            ll w = e[j].w;
            if (dist[u] + w < dist[v]){
                dist[v]=dist[u]+w;
                par[v]=u;
                x=v;
            }
        }
    }
    //now x is the last node in nth iteration , which can lies in cycle or can be another 
    //node connected with cycle that means we can come in cycle node via x (using parent vector)
    if(x==-1) return path;

    for(ll i=1;i<=n;i++){
        x=par[x];
    }
    //now x can be any node in cycle network

    ll y=x;

    while(y!=x || path.size()==0){
        path.push_back(y);
        y=par[y];
    }

    path.push_back(x);
    reverse(path.begin(),path.end());

    return path;

}

int main() {
    
    FAST
    
    ll n,m; cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v,w; cin>>u>>v>>w;
        e.push_back({u,v,w});
    }

    vector<ll> ans = bellmanPath(1,n,m);


    if(ans.size()==0) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(auto u : ans){
            cout<<u<<" ";
        }
        cout<<endl;
    }
     
    
    return 0;
}