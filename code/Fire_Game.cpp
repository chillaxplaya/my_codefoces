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
int n, m;
char Map[15][15];
int vis[15][15];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int step[15][15];
int legalCo(int x, int y) {
    return (x >= 0 && x < n) && (y >=0 && y < m);
}
vector<pair<int, int>> gnode;
int findBlock() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && Map[i][j] == '#') {
                cnt++;
                queue<pair<int, int>> qu;
                qu.push({i, j});

                while (!qu.empty()) {
                    int gx = qu.front().first;
                    int gy = qu.front().second;
                    qu.pop();
                    if (!vis[gx][gy])
                        gnode.push_back({gx, gy});
                    vis[gx][gy] = 1;
                    for (int k = 0; k < 4; k++) {
                        int ggx = gx + dir[k][0];
                        int ggy = gy + dir[k][1];
                        if(legalCo(ggx, ggy) && !vis[ggx][ggy] && Map[ggx][ggy] == '#') {
                            qu.push({ggx, ggy});
                        }
                    }
                }
            }
        }
    }

    return cnt;
}

int bfs(int x1, int y1, int x2, int y2, int gcnt) {
    memset(vis, 0, sizeof(vis));
    memset(step, 0, sizeof(step));
    queue<pair<int, int>> qu;
    int res = 0;
    qu.push({x1, y1});
    if (!(x1 == x2 && y1 == y2)) {
        qu.push({x2, y2});
    }
    
    vis[x1][y1] = 1;
    vis[x2][y2] = 1;
    while (!qu.empty()) {
        int gx = qu.front().first;
        int gy = qu.front().second;
        qu.pop();
        gcnt--;
        

        
        for (int k = 0; k < 4; k++) {
            int ggx = gx + dir[k][0];
            int ggy = gy + dir[k][1];
            if(legalCo(ggx, ggy) && !vis[ggx][ggy] && Map[ggx][ggy] == '#') {
                step[ggx][ggy] = step[gx][gy] + 1;
                res = max(res, step[ggx][ggy]);
                qu.push({ggx, ggy});
                vis[ggx][ggy] = 1;
            }
        }
    }
    if (gcnt == 0) {
        return res;
    } else {
        return 0x3f3f3f3f;
    }
}
int rd = 0;
void solve() {
    cout << "Case " << ++rd << ": ";
    memset(vis, 0, sizeof(vis));
    gnode.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> Map[i];
    }
    int block = findBlock();
    int gcnt = gnode.size();
    debug(gcnt);
    if (block > 2) {
        cout << -1 << "\n";
        return;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < gcnt; i++) {
        for (int j = i; j < gcnt; j++) {
            ans = min(ans, bfs(gnode[i].first, gnode[i].second, gnode[j].first, gnode[j].second, gcnt));
        }
    }
    cout << ans;
    cout << "\n";
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