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
    int n, x;
    int lo = -1, ro = n;
    int le = -1, re = n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2) {
            if (lo == -1) lo = i;
            ro = i;
        } else {
            if (le == -1) le = i;
            re = i;
        }
    }
    if (lo == ro) {
        cout << lo + 1 << "\n";
    } else if (le == re) {
        cout << le + 1 << "\n";
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