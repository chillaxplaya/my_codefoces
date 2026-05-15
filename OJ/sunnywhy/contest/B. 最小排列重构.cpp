/*
B. 最小排列重构
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 13:35:39
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
typedef pair<int, int> pi;
int vis[100005];

void justdoit() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> rem;
    vector<int> res;
    rep(i, m) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) rem.push_back(i);
    }
    int j = 0;
    for (int i = 0; i < m; i++) {
        for (; j < (int)rem.size(); j++) {
            if (rem[j] < a[i]) {
                res.push_back(rem[j]);
            } else {
                break;
            }
        }
        res.push_back(a[i]);
    }
    for (; j < (int)rem.size(); j++) {
        res.push_back(rem[j]);
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << res[i];
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