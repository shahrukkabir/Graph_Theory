#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'
typedef long long ll;

const int mx = 123;
bool vis[mx];
vector<int>adj[mx];

void dfs( int u ){
    cout<<u<<" ";
    vis[u]=1;
    for(auto v : adj[u]){
        if(vis[v]==0){
            dfs(v);
        }
        
    }

}
 
int main()
{
    FAST

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(5);
    adj[5].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[5].push_back(6);
    adj[6].push_back(5);

    adj[6].push_back(7);
    adj[7].push_back(6);

    for(int i=1;i<=7;i++){
        cout<<"adj["<<i<< "]  :  ";

        for(auto u : adj[i]){
            cout<<u<<" ";
        }
        cout<<nl;
    }
    cout<<nl<<nl;
    cout<<"DFS PATH :  ";
    dfs(1);

   
    return 0;
}




//dfs in grid

bool vis[mx][mx];
int dx[]={-1,+1,0,0}; 
int dy[]={0,0,-1,+1};

void dfs( int x , int y ){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=1 && x1<=n && y1>=1 && y1<=m  && vis[x1][y1]==0){
            dfs(x1,y1);
        }
    }    
}  


