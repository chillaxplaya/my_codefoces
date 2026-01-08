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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = a[0];
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        if((a[i] ^ a[i - 1]) & 1) {
            dp[i] = max(dp[i - 1] + a[i], a[i]);
            ans = max(dp[i], ans);
        } else {
            dp[i] = a[i];
            ans = max(dp[i], ans);
        }
    }
    cout << ans << endl;
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