/*
C - Omelette Restaurant
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc446/tasks/abc446_c
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
    int n, d, x, maxi = 0;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        cin >> x;
        for (int j = max(max(0, i - d), maxi); j <= i; j++) {
            if (x <= a[j]) {
                a[j] -= x;
                break;
            } else {
                x -= a[j];
                a[j] = 0;
                maxi = j + 1;
            }

        }
    }
    int res = 0;
    for (int i = n - d; i < n; i++) {
        res += a[i];
    }
    debug(a);
    cout << res << endl;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}