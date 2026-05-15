/*
寻找指定元素V
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 12:17:51
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
int binarys(const vector<int> &a, int l, int r, int x) {
    while(l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] > x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
void justdoit() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    int res = binarys(a, 0, n, x);
    debug(res);
    if (res > 0) {
        cout << (a[res - 1] == x ? res - 1 : -1);
    } else {
        cout << res - 1;
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