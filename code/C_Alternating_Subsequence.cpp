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
bool diffsig(int x, int y) {
    if (x > 0 && y < 0) return true;
    if (x < 0 && y > 0) return true;
    return false;
}
void solve() {
    int n;
    ll x, ans = 0;
    cin >> n;
    vector<ll> a;
    cin >> x;
    ll pre = x;
    ll maxpre = x;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (!diffsig(pre, x)) {
            maxpre = max(maxpre, x);
        } else {
            a.push_back(maxpre);
            maxpre = x;
        }
        pre = x;
    }
    a.push_back(maxpre);
    for (auto e : a) {
        ans += e;
        debug(e);
    }
    debug(a);
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