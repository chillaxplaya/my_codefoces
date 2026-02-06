#include <bits/stdc++.h>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
//0 1 2 3 4 5 6 7 ... n - 1
void justdoit() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    vector<int> c(n, 0);
    vector<int> ab(n, 0);
    rep(i, n) {
        cin >> a[i];
        if (i != 0)
            a[i] += a[i - 1];
    }
    rep(i, n) {
        cin >> b[i];
        if (i != 0)
            b[i] += b[i - 1];
    }
    rep(i, n) {
        cin >> c[i];
        if (i != 0)
            c[i] += c[i - 1];
    }
    debug(a);
    debug(b);
    debug(c);
    for (int i = 1; i < n - 1; i++) {
        ab[i] = max(ab[i - 1], a[i - 1] + b[n - 1] - b[i - 1]);
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        ans = max(ans, c[n - 1] - c[i - 1] + ab[i - 1] - (b[n - 1] - b[i - 1]));
    }
    cout << ans;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}