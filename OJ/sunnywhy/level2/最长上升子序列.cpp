/*
最长上升子序列
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 18:35:12
*/
#include <bits/stdc++.h>
#include <algorithm>
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

void justdoit() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res;
    rep(i, n) {
        cin >> a[i];
        auto it = upper_bound(all(res), a[i]);
        if (it == res.end()) {
            res.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << res.size();
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