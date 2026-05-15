/*
奶牛队列2
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 12:01:45
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
    unordered_set<int> cnt;
    int type = 0;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        if (!cnt.count(y)) {
            type++;
            cnt.insert(y);
        }
    }
    sort(all(a));
    for (int i = 1; i < n; i++) {
        a[i].first -= a[0].first;
    }
    a[0].first = 0;
    unordered_map<int, int> vis;
    int left = 0;
    int ans = 0x3f3f3f3f;
    for (int right = 0; right < n; right++) {
        vis[a[right].second]++;
        debug(vis.size(), type);
        while (vis.size() == type && left <= right) {
            debug(a[right].first, a[left].first);
            ans = min(ans, a[right].first - a[left].first);
            vis[a[left].second]--;
            if (vis[a[left].second] == 0) {
                vis.erase(a[left].second);
            }
            left++;
        }
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