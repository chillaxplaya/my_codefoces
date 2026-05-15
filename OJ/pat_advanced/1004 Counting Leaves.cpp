/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int> pi;
void justdoit() {
    int n, m, k, u, v;
    cin >> n >> m;
    vector<vector<int>> g(100);
    rep(i, m) {
        cin >> u;
        cin >> k;
        rep(i, k) {
            cin >> v;
            g[u].push_back(v);
        }
    }
    vector<int> cnt(100);
    vector<int> vis(100, 0);
    int maxheight = 0;
    auto dfs = [&](int now, int h, auto &&self) {
        maxheight = max(maxheight, h);
        if (g[now].size() == 0) {
            cnt[h]++;
            return;
        }
        for (auto &e : g[now]) {
            self(e, h + 1, self);
        }
    };
    cnt.resize(n + 1);
    dfs(1, 0, dfs);
    cnt.resize(maxheight + 1);
    for (int i = 0; i < maxheight + 1; i++) {
        if (i) cout << " ";
        cout <<cnt[i];
    }
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}