/*
C. Maximum Median
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1201/C
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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    int mid = n / 2;
    for (int i = mid + 1; i < n; i++) {
        if (k < 1LL * (a[i] - a[i - 1]) * (i - mid)) {
            cout << a[i - 1] + k /  (i - mid);
            return;
        }
        k -= 1LL * (a[i] - a[i - 1]) * (i - mid);
    }
    cout << k / (mid + 1) + a[n - 1];
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