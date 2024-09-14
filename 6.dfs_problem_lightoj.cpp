//1.https://lightoj.com/problem/back-to-underworld

#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;

//প্রশ্নে অনেকগুলো bipartite (২ টা কালারে কালার করা যাবে ) গ্রাফ দেওয়া আছে, এখন 
//প্রত্যেকটি গ্রাফে সর্বোচ্চ কালার(২ টি কালারের মধ্যে যে কালারটি বেশি) যেটি তাদের যোগফল বাহির করতে হবে।

const int mx = 2e4+123;
bool vis[mx];
vector<int> adj[mx];
bool isNode[mx];
ll cnt, cnt1;

void dfs ( int u, int col )
{
    vis[u] = 1;
    if ( col == 1 ) cnt1++;
    cnt++;

    int tmp;
    if ( col == 1 ) tmp = 2;
    else tmp = 1;

    for ( auto v : adj[u] ) {
        if (  vis[v] == 0 ) {
            dfs ( v, tmp );
        }
    }
}

int main() {
    FAST

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= mx; j++) {
            adj[j].clear();
            isNode[j] = 0;
            vis[j] = 0;
        }
        int e; cin >> e;
        while (e--) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            isNode[u] = 1;
            isNode[v] = 1;
        }
        int ans = 0;
        for (int j = 1; j <= mx; j++) {
            if (isNode[j] == 1 && vis[j] == 0) {
                cnt = 0; cnt1 = 0;
                dfs(j, 1);
                ans += max(cnt1, cnt - cnt1);
            }
        }
        cout << "Case " << i << ": " << ans << nl;
    }

    return 0;
}


//2.https://lightoj.com/problem/guilty-prince

//প্রশ্নে ' . ' হচ্ছে  মাটি এবং ' # ' হচ্ছে পানি যেখানে যেতে পারবে না,  এখন কেউ ' @ ' থেকে শুরু করে সর্বোচ্চ 
//কতগুলো নোডে ভিজিট করতে পারবে / ' @ ' সংলগ্ন maximum size of connected component বাহির করতে হবে।

#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;
#define mem(a,b) memset(a, b, sizeof(a) )

int cnt,m,n;
const int mx = 23 ;
bool vis[mx][mx];
char c[mx][mx];
int dx[]={-1,+1,0,0}; 
int dy[]={0,0,-1,+1};

void dfs( int x , int y ){
    vis[x][y]=1;
    cnt++;
    for(int i=0;i<4;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=1 && x1<=n && y1>=1 && y1<=m && c[x1][y1]=='.' && vis[x1][y1]==0){
            dfs(x1,y1);
        }
    }    
} 

int main() {
    FAST   
    int t; cin>>t;
    for(int i=1;i<=t;i++){
        mem(vis,0);
        int x,y;
        cin>>m>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
                if(c[i][j]=='@'){
                    x=i;
                    y=j;
                }
            }
        }
        cnt=0;
        dfs(x,y);
        cout<<"Case "<<i<<": "<<cnt<<nl;
        
    }
    
    return 0;
}