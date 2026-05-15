/*
大小数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 14:20:45
*/
#include <bits/stdc++.h>
#include <algorithm>
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
int binarys(vector<int> &a, int l, int r, int x) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
void justdoit() {
    int n, m, l, r;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    cin >> l >> r;
    ll ans = 0;
    rep(i, m) {
        if (b[i] > r) break;
        int idx1 = binarys(a, 0, n, l - b[i]);
        int idx2 = binarys(a, 0, n, r - b[i] + 1);
        ans += (idx2 - idx1);
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