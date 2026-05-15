/*
B - Fruit Sorting
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/awc0002/tasks/awc0002_b
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
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    int cnt = 0;
    rep(i, m) {
        cin >> x;
        if (a[x - 1] < k) {
            cnt++;
            sum += a[x - 1];
        }
    }
    cout << cnt << " " << sum;
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