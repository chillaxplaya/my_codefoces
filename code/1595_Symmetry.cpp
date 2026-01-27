#include <bits/stdc++.h>
#include <vector>
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
    int x, y;
    cin >> n;
    vector<pair<int, int>> a(n);
    set<pair<int, int>> node;
    int minx = 10000, maxx = -10000;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        node.insert({x, y});
        a[i] = {x, y};
        minx = min(x, minx);
        maxx = max(x, maxx);
    }
    int mid = (minx + maxx);
    for (auto e : a) {
        if (!node.count({mid - e.first, e.second})) {
            debug(mid);
            debug(mid - e.first, e.second);
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
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