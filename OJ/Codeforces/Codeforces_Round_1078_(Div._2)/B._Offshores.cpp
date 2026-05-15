/*
B. Offshores
Time Limit: 1500ms Memory Limit: 256MB
URL: https://codeforces.com/contest/2194/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define INF 0x3f3f3f3f

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll contri = 0;
    rep(i ,n) {
        cin >> a[i];
        contri += a[i] / x * y;
    }
    ll ans = 0;
    rep(i ,n) {
        ans = max(ans, a[i] + contri - a[i] / x * y);
    }
    cout << ans << "\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}