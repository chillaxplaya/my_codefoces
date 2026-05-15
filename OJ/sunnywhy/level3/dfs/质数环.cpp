/*
质数环
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-12 13:04:27
user: playa
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
#define endl '\n'
unordered_set<int> prims;
int vis[100];
int n;
int res[2000];
bool dfs(int k) {
    if (k == n) {
        if (prims.count(res[k - 1] + res[0])) {
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << res[i];
            }
            return true;
        }
        return false;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && (k == 0 || prims.count(res[k - 1] + i))) {
            vis[i] = 1;
            res[k] = i;
            if (dfs(k + 1)) {
                return true;
            }
            vis[i] = 0;
        }
    }
    return false;
}
void justdoit() {
    cin >> n;
    if (n > 1 && n % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 2; i <= 2 * n; i++) {
        bool ok = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            prims.insert(i);
        }
    }
    vector<int> res;
    bool ok = dfs(0);
    if (!ok) {
        cout << -1;
    }
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