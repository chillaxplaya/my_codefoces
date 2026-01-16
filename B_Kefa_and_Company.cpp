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
    int n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> a;
    map<ll, ll> c;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        c[x] += y;
    }
    for (auto e : c) {
        a.push_back({e.first, e.second});
    }
    int l = 0, r = 0;
    ll ans = a[0].second, sum = a[0].second;
    debug(a);
    while (1) {
        if (r < a.size() - 1 && a[r + 1].first - a[l].first < d) {
            r++;
            sum += a[r].second;
            ans = max(ans, sum);
        } else if (l < r) {
            sum -= a[l].second;
            ans = max(ans, sum);
            l++;
        } else if (l == r && l != a.size() - 1) {
            sum -= a[l].second;
            l++;
            r++;
            sum += (ll)a[l].second;
            ans = max(ans, sum);
        }
        if (l == a.size() - 1) {
            ans = max(ans, sum);
            break;
        }
    }
    cout << ans << endl;
}
int main() {
    debug(INT_MAX);
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}