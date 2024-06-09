#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'
typedef long long ll;

const int mx = 1e4+123;
vector<int> adj[mx];
int lev[mx];

void bfs(int s) {
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;                         //source level zero
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : adj[u]) {
            if (lev[v] == -1) {         //if unvisited
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
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

    for (int i = 1; i <= 7; i++) {
        cout << "adj[" << i << "]  :  ";
        for (auto u : adj[i]) {
            cout << u << " ";
        }
        cout << nl;
    }
    cout << nl << nl;
    cout << "BFS PATH: ";
    bfs(1);

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
                                              //Implementation BFS for grid
const int mx = 100; 
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};
int lev[mx][mx];                              // Level array to store the distance to each node
int n, m;                                     // Dimensions of the grid

void bfs(int x, int y) {
    memset(lev, -1, sizeof(lev));            // Initialize levels with -1
    lev[x][y] = 0;                           // Starting point level is 0
    queue<pair<int, int>> q;                 // Queue to store coordinates
    q.push({x, y});                          // Push starting coordinates into the queue

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            // Ensure the new coordinates are within bounds and not yet visited
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && lev[x1][y1] == -1) {
                lev[x1][y1] = lev[x][y] + 1; // Update level for the new node
                q.push({x1, y1}); // Push new coordinates into the queue
            }
        }
    }
}
