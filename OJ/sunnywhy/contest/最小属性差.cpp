/*
最小属性差
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 21:10:06
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

void justdoit() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[f, s] : a) {
        cin >> f >> s;
    }
    int limit = (1 << n);
    int ans = 0x3f3f3f3f;
    for (int condi = 1; condi < limit; condi++) {
        int con = 1, sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (condi & (1 << i)) {
                con *= a[i].first;
                sum += a[i].second;
            }
        }
        ans = min(ans, abs(con - sum));
    }
    cout << ans;
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