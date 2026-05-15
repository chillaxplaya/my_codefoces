/*
组合锁
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 18:03:29
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
int n;
int a[3];
int b[3];
int c[3];
bool ja() {
    rep(i, 3) {
        int l = a[i] - c[i];
        int r = c[i] - a[i];
        l = (l < 0 ? l + n : l);
        r = (r < 0 ? r + n : r);
        if (min(l, r) > 2) {
            return false;
        }
    }
    return true;
}
bool jb() {
    rep(i, 3) {
        int l = b[i] - c[i];
        int r = c[i] - b[i];
        l = (l < 0 ? l + n : l);
        r = (r < 0 ? r + n : r);
        if (min(l, r) > 2) {
            return false;
        }
    }
    return true;
}
void justdoit() {
    cin >> n;
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    int res = 0;
    for (int i = 1; i <= n; i++) {
        c[0] = i;
        for (int j = 1; j <= n; j++) {
            c[1] = j;
            for (int k = 1; k <= n; k++) {
                c[2] = k;
                if (ja() || jb()) {
                    res++;
                }
            }
        }
    }
    cout << res;
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