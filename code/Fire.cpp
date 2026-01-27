#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
char Map[1005][1005];
int dis[1005][1005];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void solve() {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> qu;
    debug(n, m);
    memset(dis, 0, sizeof(dis));
    int jx, jy;
    auto legalCo = [n, m](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    auto inBd = [n, m](int x, int y){
        return x == 0 || x == n - 1 || y == 0 || y == m - 1;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'F') {
                qu.push({i, j});
            } else if (Map[i][j] == 'J') {
                jx = i;
                jy = j;
            }
        }
    }
    qu.push({jx, jy});
    while (!qu.empty()) {
        int mx = qu.front().first;
        int my = qu.front().second;
        qu.pop();
        
        if (Map[mx][my] == 'J' && inBd(mx, my)) {
            cout << dis[mx][my] + 1 << "\n";
            return;
        }
        for (int i = 0; i < 4; i++) {
            int gx = mx + dir[i][0];
            int gy = my + dir[i][1];
            if (legalCo(gx, gy) && Map[gx][gy] == '.') {
                Map[gx][gy] = Map[mx][my];
                dis[gx][gy] = dis[mx][my] + 1;
                qu.push({gx, gy});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}