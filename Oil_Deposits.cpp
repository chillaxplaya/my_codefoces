#include <bits/stdc++.h>
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
char Map[105][105];
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void solve() {
    int n, m;
    while (cin >> n >> m && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> Map[i][j];
            }
        }
        auto legalCo = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        auto dfs = [&](auto&& self,int x, int y) -> void {
            Map[x][y] = '*';
            for (int i = 0; i < 8; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (legalCo(nx, ny) && Map[nx][ny] == '@') {
                    self(self, nx, ny);
                }
            }
        };
        auto bfs = [&](int x, int y) {
            
        };
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (Map[i][j] == '@') {
                    dfs(dfs, i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}