#include <bits/stdc++.h>

#include <climits>

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

#define all(x) (x).begin(), (x).end()
#define ll long long
vector<ll> primes;
ll minll(ll a, ll b, ll c) { return min(a, min(b, c)); }
void solve() {
    vector<ll> dp(1500);
    dp[0] = 1;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    for (int i = 1; i < 1500; i++) {
        ll p1 = dp[idx1] * 2;
        ll p2 = dp[idx2] * 3;
        ll p3 = dp[idx3] * 5;
        ll minp = minll(p1, p2, p3);
        if (minp == p1) {
            idx1++;
        }
        if (minp == p2) {
            idx2++;
        }
        if (minp == p3) {
            idx3++;
        }
        debug(minp);
        dp[i] = minp;
    }
    printf("The 1500'th ugly number is %lld.", dp[1499]);
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