/*
C - Not Covered Points
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc462/tasks/abc462_c
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

void justdoit() {
    int n;
    cin >> n;
    int x, y;
    vector<pi> p;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end(), [](pi &a, pi &b) {
        return a.first < b.first;
    });
    int maxr = n + 1;
    int ans = 0;
    for (auto &xy : p) {
        if (xy.second < maxr) {
            maxr = xy.second;
            ans++;
        }
    }
    cout << ans << endl;
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