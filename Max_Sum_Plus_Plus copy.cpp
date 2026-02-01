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
#define MAXN 1005
int m, n;
void solve() {
    
    while (cin >> m >> n) {
        vector<int> a(n + 1);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        vector<vector<int>> local(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        dp[0][0] = -1e9;
        for (int i = 1; i <= m; i++) {
            dp[i][i - 1] = -1e9;
            for (int j = i; j <= n; j++) {
                // if (i == 1 && j == 1) {
                //     debug(local[i][j - 1], dp[i - 1][j - 1]);
                // }
                local[i][j] = max(local[i][j - 1], dp[i - 1][j - 1]) + a[j];
                dp[i][j] = local[i][j];
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        cout << dp[m][n] << '\n';
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