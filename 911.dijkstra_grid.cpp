// For 1 based indexing

#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;
typedef pair<ll, ll> pll;

int dx[] = { 0, 0, +1, -1 };  // Right, Left, Down, Up
int dy[] = { +1, -1, 0, 0 };

// int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
// int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

void shortest(vector<vector<int>> &grid, int n, int m, vector<vector<ll>> &dist) {

    // Initialize the distances with a large number
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = LONG_MAX;
        }
    }     
    // priority_queue< pair<long long, pair<ll, ll> >, vector<pair<long long, pair<ll, ll>>>, greater<pair<long long, pair<ll, ll> >>> pq; 

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;

    dist[1][1] = grid[1][1];
    pq.push({grid[1][1], {1, 1}}); // {cost, {x, y}}

    while (!pq.empty()) {
        pair<int, int> u = pq.top().second;
        ll curD = pq.top().first;
        pq.pop();

        int x = u.first;
        int y = u.second;

        // If the current distance is already greater than the stored one, skip it
        if (curD > dist[x][y]) continue;

        // Explore neighbors in 4 directions (up, down, left, right)
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            // Check if the neighbor is within grid bounds and if we can find a shorter path
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && curD + grid[x1][y1] < dist[x1][y1]) {
                dist[x1][y1] = curD + grid[x1][y1];
                pq.push({dist[x1][y1], {x1, y1}});
            }
        }
    }
}

int main() {
    FAST

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    vector<vector<ll>> dist(n + 1, vector<ll>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    shortest(grid, n, m, dist);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << nl; 
    }

    return 0;
}



//Zero-Based Indexing :


#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define nl '\n'
typedef long long ll;
typedef pair<ll, ll> pll;

const int mx = 1e3 + 5; 

int dx[] = { 0, 0, +1, -1 };
int dy[] = { +1, -1, 0, 0 }; 

vector<vector<ll>> dist(mx, vector<ll>(mx, LONG_MAX)); 

void shortest(vector<vector<int>> &grid, int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = LONG_MAX; 
        }
    }

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;

    dist[0][0] = grid[0][0];  
    pq.push({grid[0][0], {0, 0}}); 

    while (!pq.empty()) {
        pair<int, int> u = pq.top().second;
        ll curD = pq.top().first;
        pq.pop();

        int x = u.first;
        int y = u.second;

        if (curD > dist[x][y]) continue;

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && curD + grid[x1][y1] < dist[x1][y1]) {
                dist[x1][y1] = curD + grid[x1][y1];
                pq.push({dist[x1][y1], {x1, y1}});
            }
        }
    }
}

int main() {
    FAST

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j]; 
        }
    }

    shortest(grid, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << nl;
    }

    return 0;
}

