/*
全排列I
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 18:00:21
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
int vis[15];
int a[15];
int n;
int b[15];
void dfs(int k) {
    if (k == n) {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            a[k] = b[i - 1];
            dfs(k + 1);
            vis[i] = 0;
        }
    }
} 
void justdoit() {
    cin >> n;
    rep(i, n) {
        cin >> b[i];
    }
    dfs(0);
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