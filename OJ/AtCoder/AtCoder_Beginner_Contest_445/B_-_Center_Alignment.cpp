/*
B - Center Alignment
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc445/tasks/abc445_b
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

void justdoit() {
    int n, maxl = 0;
    cin >> n;
    vector<string> a(n);
    rep(i, n) {
        cin >> a[i];
        maxl = max(maxl, (int)a[i].size());
    }
    for (auto e : a) {
        int j = maxl - e.size();
        j /= 2;
        rep(i, j) cout << '.';
        cout << e;
        rep(i, j) cout << '.';
        cout << '\n';
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