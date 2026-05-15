/*
奶牛大学的学费
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 12:53:33
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    sort(all(a));
    ll maxfee = 0;
    ll maxsum = 0;
    for (int i = 0; i < n; i++) {
        if (1LL * a[i] * (n - i) > maxsum) {
            maxfee = a[i];
            maxsum = a[i] * (n - i);
        }
    }
    cout << maxsum << " " << maxfee;
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