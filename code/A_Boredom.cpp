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
int dp[100005];
int cnt[100005];
void solve() {
    int n, x;
    cin >> n;
    rep(i ,n) {
        cin >> x;
        cnt[x]++;
    }
    dp[1] = 1 * cnt[1];
    for (int i = 2; i <= 10000; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
    }
    cout << dp[10000] << '\n';
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