#include <bits/stdc++.h>
#include <algorithm>
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
#define rep(i,n) for (int i = 0; i < n; i++)

void solve() {
    int n;
    while (cin >> n && n) {
        debug(n);
        vector<int> a(n);
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i] = a[i];
        }
        rep(i, n)
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
            }
        cout << *max_element(all(dp)) << "\n";
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