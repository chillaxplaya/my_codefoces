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
int dfs(int n, int m, int k, unordered_set<int> & vis) {
    if (n == m) {
        return k;
    }
    if (vis.count(n)) {
        return -1;
    }
    vis.insert(n);
    int a = dfs((n + 1) / 2, m, k + 1, vis);
    int b = dfs(n / 2, m, k + 1, vis);
    if (a != -1 && b != -1) {
        return min(a, b);
    }
    if (a != -1) {
        return a;
    }
    if (b != -1) {
        return b;
    }
    return -1;
}
void solve() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> vis;
    cout << dfs(n, m, 0, vis) << endl;
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