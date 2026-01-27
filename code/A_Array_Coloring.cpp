#include <bits/stdc++.h>
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

void solve() {
    int n;
    cin >> n;
    int a[2], t, x;
    cin >> a[0] >> a[1];
    if (n == 2) {
        cout << "YES" << endl;
        return;
    }
    n -= 2;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if ((x & 1) != (a[i % 2] & 1)) { ok = false; }
    }
    if (ok)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}