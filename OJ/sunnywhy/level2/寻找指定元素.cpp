/*
寻找指定元素
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 17:20:57
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
vector<int> a;
int lower_b(int l, int r, int x) {
    while(l < r) {
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
    int n, x;
    cin >> n >> x;
    a.resize(n);
    for (auto &e : a) {
        cin >> e;
    }
    sort(all(a));
    int t = lower_b(0, n, x);cout << t;
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