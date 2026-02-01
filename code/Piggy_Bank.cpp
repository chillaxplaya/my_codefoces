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
#define rep(i,n) for (int i = 0; i < n; i++)

void solve() {
    int e, f;
    cin >> e >> f;
    int n, m = f - e;
    cin >> n;
    vector<int> v(n);
    vector<int> w(n);
    vector<int> dp(m + 1,0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 1; j++) {
            for (int k = j * w[i]; k <= m; k++) {
                if (dp[k] > dp[k - j * w[i]] + j * v[i]) {
                    dp[k] = dp[k - j * w[i]] + j * v[i];
                }
            }
        }
        debug(v[i],w[i]);
        debug(i,dp);
    }
    if (dp[m] < 0x3f3f3f3f / 2) {
        cout << "The minimum amount of money in the piggy-bank is " << dp[m] << ".\n";
    } else {
        cout << "This is impossible.\n";
    }
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