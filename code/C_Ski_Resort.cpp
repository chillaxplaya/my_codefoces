#include <bits/stdc++.h>
#include "algo/debug.h"

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define ll long long
ll addsum(int l, int r, int k) {
    if(r - l >= k) {
        int t = (r - l - k) + 1;
        return 1LL * t * (t + 1) / 2; 
    }
    return 0;
}
void solve() {
    int n, k, q, x;
    cin >> n >> k >> q;
    int pre = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x <= q) {
            if (pre == -1) {
                pre = i;
            }
            if (i == n - 1) {
                ans += addsum(pre, n, k);
            }
        } else if(pre != -1) {
            ans += addsum(pre, i, k);
            pre = -1;
        }
        debug(INT_MAX);
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