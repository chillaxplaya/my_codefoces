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
unordered_map<int, ll> cnt;
//3 5 7
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e : a) {
        cin >> e;
    }
    ll ans = 0;
    for (auto &e : a) {
        if (e % 5 == 0) {
            cnt[e]++;
            ans += ((cnt.count(e / 5 * 3) ? cnt[e / 5 * 3] : 0) * (cnt.count(e / 5 * 7) ? cnt[e / 5 * 7] : 0));
        } else if (e % 7 == 0) {
            cnt[e]++;
        } else if(e % 3 == 0) {
            cnt[e]++;
        }
    }
    reverse(all(a));
    cnt.clear();
    for (auto &e : a) {
        if (e % 5 == 0) {
            cnt[e]++;
            ans += (1LL * cnt[e / 5 * 3] * cnt[e / 5 * 7]);
        } else if (e % 7 == 0) {
            cnt[e]++;
        } else if(e % 3 == 0) {
            cnt[e]++;
        }
    }
    cout << ans << '\n';
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