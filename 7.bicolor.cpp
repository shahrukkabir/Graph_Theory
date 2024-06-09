#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;

const int mx = 300;
vector<int>adj[mx];
int col[mx];

bool isBicolor (int s){
    memset(col,-1,sizeof(col));
    col[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int curCol;
        if(col[u]==1){
            curCol=2;
        }
        else{
            curCol=1;
        }
        for( auto v: adj[u] ){
            if(col[v]==-1){
                col[v]=curCol;
                q.push(v);
            }
            else if(col[v]==col[u]){  //pasapasi adjacent node er color same
                return 0;
            }
        }
    }
    return 1;
}


int main() {
    FAST
    
     
    
    return 0;
}