#include <bits/stdc++.h>
#include <vector>
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
int nxt[21];
int vis[21];
int rd = 0;
void dfs(vector<vector<int>> &a, int now, int h, int &fnl) {
    if (h == 19 && (now == a[fnl][0] || now == a[fnl][1] || now == a[fnl][2])) {
        int t = fnl;
        cout << ++rd << ": ";
        while(t != now) {
            cout << " " << t;
            t = nxt[t];
        }
        cout << " " << now << " " << fnl << " \n";
        return;
    }
    if (vis[a[fnl][0]] && vis[a[fnl][1]] && vis[a[fnl][2]]) {
        return;
    }
    debug(h);
    for (int i = 0; i < 3; i++) {
        if (vis[a[now][i]] == 0) {
            vis[a[now][i]] = 1;
            nxt[now] = a[now][i];
            dfs(a, a[now][i], h + 1, fnl);
            vis[a[now][i]] = 0;
        }
    }
}
void solve() {
    vector<vector<int>> a(21);
    int x;
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> x;
            a[i].push_back(x);
        }
        if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
        if (a[i][1] > a[i][2]) swap(a[i][1], a[i][2]);
        if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
    }
    
    int t;
    while (cin >> t && t) {
        vis[t] = 1;
        dfs(a, t, 0, t);
        vis[t] = 0;
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