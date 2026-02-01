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
// ll dp1[50005][1005];
// ll p[500005];
// ll v[500005];
// ll dp2[50005][1005];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp1(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> dp2(n + 2, vector<ll>(m + 1));
    vector<ll> p(n + 1);
    vector<ll> v(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = p[i]; j <=m; j++) {
            if (j < p[i]) {
                dp1[i][j] = dp1[i - 1][j];
            }
            else
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - p[i]] + v[i]);
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            if ( j < p[i]) {
                dp2[i][j] = dp2[i + 1][j];
            }
            else
                dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - p[i]] + v[i]);
        }
    }
    ll tgt = dp1[n][m];
    string ans;
    debug(tgt);
    for (int i = 1; i <= n; i++) {
        ll sum_notinclu_i = 0;
        for (int j = 0; j <= m; j++) sum_notinclu_i = max(sum_notinclu_i, dp1[i - 1][j] + dp2[i + 1][m - j]);
        ll sum_inclu_i = 0;
        for (int j = 0; j <= m - p[i]; j++) sum_inclu_i = max(sum_inclu_i, dp1[i - 1][j] + dp2[i + 1][m - p[i] - j]);
        debug(sum_notinclu_i, sum_inclu_i);

        if (sum_notinclu_i < tgt) ans += 'A';
        else if (sum_inclu_i < tgt - v[i]) ans += 'C';
        else ans += 'B';
    }
    cout << ans << endl;
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