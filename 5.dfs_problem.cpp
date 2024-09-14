//1.Connected Components in a Graph: https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

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


//2.Maximum component size 

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

//3.https://cses.fi/problemset/task/1192/
//Solution: https://cses.fi/paste/be63a8781ab88fce958269/

#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;

int dx[]={-1,+1,0,0}; 
int dy[]={0,0,-1,+1};

const int mx = 1e3+123;
char c[mx][mx];
bool vis[mx][mx];
int n,m; 


void dfs( int x, int y ){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
       int x1 = x + dx[i];
       int y1 = y + dy[i];
       if( x1>=1 && x1<=n && y1>=1 && y1<=m && c[x1][y1]=='.' && vis[x1][y1]==0 ){
         dfs(x1,y1);
       }
    }
} 


int main() {
    
    FAST
    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if( c[i][j] == '.' && vis[i][j]==0 ){
                    dfs(i,j);
                    cnt++;
            }
        }
    }
    
    cout<<cnt<<nl;

    return 0;
}


//4.https://cses.fi/problemset/task/1666
//Solution:https://cses.fi/paste/e203875282e0fc5e957f03/

#include <bits/stdc++.h>
using namespace std;
 
#define nl '\n'
 
const int mx = 1e5+123;
vector<int>adj[mx];
bool vis[mx];
 
void dfs( int u ){
    vis[u]=1;
    // cout<<u<<' ';
    for(auto v : adj[u]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}
 
int main() {
    
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt=0;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            ans.push_back(i);
            cnt++;
        }
    }
    cout<<cnt-1<<nl; 
 
    for(int i=1;i<ans.size();i++){
        cout<<ans[i-1]<<' '<<ans[i]<<nl;
    }
    
    return 0;
}
