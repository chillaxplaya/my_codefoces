/*
恰好两个零
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 14:42:15
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
int cnt(const string &a, const string &b) {
    int c = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) c++;
    }
    return c;
}
void justdoit() {
    int n, s;
    cin >> n >> s;
    vector<bitset<30>> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int ans = 35;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int res = (a[i] ^ a[j]).count();
            ans = min(res, ans);
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