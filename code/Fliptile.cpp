#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                                           \
    cerr << "[" << #a << "] = {";                                 \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";
int Map[20][20];
int op[20][20];
int n, m;
#define IMPOSSIBLE "IMPOSSIBLE"
#define all(x) (x).begin(), (x).end()
#define ll long long
// IMPOSSIBLE
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans = 0x3f3f3f3f;
int ansmap[20][20];
void invs(int x, int y, int b[20][20]) {
    b[x][y] = 1 - b[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            b[nx][ny] = 1 - b[nx][ny];
        }
    }
}
int f[20];
void coopy(int a[20][20], int b[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { b[i][j] = a[i][j]; }
    }
}
void dfs(int d) {
    if (d == m) {
        int b[20][20];
        coopy(Map, b);
        memset(op, 0, sizeof(op));
        int opcnt = 0;
        for (int i = 0; i < m; i++) {
            if (f[i] == 1) {
                invs(0, i, b);
                opcnt += 1;
                op[0][i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i - 1][j] == 1) {
                    invs(i, j, b);
                    opcnt += 1;
                    op[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (b[n - 1][i] == 1) { return; }
        }
        if (opcnt < ans) {
            debug(opcnt);
            ans = opcnt;
            coopy(op, ansmap);
        }
        return;
    }

    f[d] = 0;
    dfs(d + 1);
    f[d] = 1;
    dfs(d + 1);
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { cin >> Map[i][j]; }
    }
    debug(n);
    dfs(0);
    debug(m);
    if (ans == 0x3f3f3f3f) {
        cout << IMPOSSIBLE << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << ' ';
            cout << ansmap[i][j];
        }
        cout << "\n";
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}