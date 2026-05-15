/*
C - Sugoroku Destination
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc445/tasks/abc445_c
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
int a[105][500005];
void justdoit() {
    int n;
    cin >> n;
    rep(i, n) cin >> a[0][i + 1];
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= n; j++) {
            int t = j;
            rep(k, 10) t = a[i - 1][t];
            a[i][j] = t;
        }
    }
    rep(i, n) {
        cout << a[100][i + 1] << " ";
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