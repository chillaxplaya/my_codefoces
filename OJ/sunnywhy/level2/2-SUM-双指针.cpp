/*
2-SUM-双指针
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 10:24:16
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
        if (a[l] + a[r] == k) {
            ans++;
            l++;
            r--;
        } else if (a[l] + a[r] < k) {
            l++;
        } else if (a[l] + a[r] > k) {
            r--;
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