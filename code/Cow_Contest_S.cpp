#include <bits/stdc++.h>
#include <vector>
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
int lk[105][105];
int incnt[105];
typedef pair<int, int> pi;
void solve() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        lk[x][y] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n;j ++) {
                lk[i][j] = lk[i][j] || (lk[i][k] && lk[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int r = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            r = r && (lk[i][j] || lk[j][i]);
        }
        ans += r;
    }
    cout << ans << "\n";
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