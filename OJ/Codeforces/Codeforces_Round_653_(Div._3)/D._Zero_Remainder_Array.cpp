/*
D. Zero Remainder Array
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1374/D
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i] %= k;
    }
    sort(all(a));
    ll ans = -1;
    for (int i = 0; i < n;) {
        if (a[i] == 0) {
            i++;
            continue;
        }
        int l = i + 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= a[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        ans = max(ans, 1LL * (k - a[i]) + 1LL * (l - i - 1) * k);
        i = l;
    }
    cout << (ans + 1) << "\n";
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