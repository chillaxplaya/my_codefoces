/*
组合I
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 18:07:50
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
int a[1000];
int b[1000];
void dfs(int pre, int h, int k, int n) {
    if (k == h) {
        for (int i = 0; i < k; i++) {
            if (i) cout << " ";
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = pre + 1; i <= n; i++) {
        a[h] = b[i - 1];
        debug(h);
        dfs(i, h + 1, k, n);
    }
}
void justdoit() {
    int n, k;
    cin >> n >> k;
    rep(i, n) {
        cin >> b[i];
    }
    dfs(0, 0, k, n);
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