/*
斐波拉契数列
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 16:13:12
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
int dfs(int k, int h) {
    // cout << h << endl;
    
    rep(i, h) {
        cout << "    ";
    }
    cout << "n=" << k << endl;
    if (k == 1 || k == 2) {
        return 1;
    }
    return dfs(k - 1, h + 1) + dfs(k - 2, h + 1);
}
void justdoit() {
    int n;
    cin >> n;
    dfs(n, 0);
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