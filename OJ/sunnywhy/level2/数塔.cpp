/*
数塔
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 16:22:28
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
int n, x;
vector<vector<int>> a;
int dfs(int k, int h) {
    if (h == n) return 0;
    return max(dfs(k, h + 1), dfs(k + 1, h + 1)) + a[h][k];
}
void justdoit() {
    
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    cout << dfs(0, 0);
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