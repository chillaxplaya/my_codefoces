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
int rd = 0;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pre(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = i;
        dp[i] = a[i];
    }
    int maxdp = dp[0];
    int maxi = 0;
    for (int i = 1; i < n; i++) {
        if(dp[i - 1] + a[i] >= dp[i]) {
            pre[i] = pre[i - 1];
            dp[i] = dp[i - 1] + a[i];
        }
        if(dp[i] > maxdp) {
            maxdp = dp[i];
            maxi = i;
        }
    }
    debug(dp);
    cout << "Case " << ++rd <<":\n";
    cout << maxdp << " " << pre[maxi] + 1 << " " << maxi + 1 << "\n\n";
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