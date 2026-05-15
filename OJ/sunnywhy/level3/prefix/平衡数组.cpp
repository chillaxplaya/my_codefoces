/*
平衡数组
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 15:56:45
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
    vector<ll> a(n);
    vector<ll> pre2(n);
    vector<ll> pre3(n);
    for (auto &e : a) {
        cin >> e;
    }
    for (int i = 0; i < n; i++) {
        pre2[i] = (i > 0 ? pre2[i - 1] + (a[i] == 2) : (a[i] == 2));
        pre3[i] = (i > 0 ? pre3[i - 1] + (a[i] == 3) : (a[i] == 3));
    }
    for (int i = 0; i < n - 1; i++) {
        if (pre2[i] == pre2[n - 1] - pre2[i] && pre3[i] == pre3[n - 1] - pre3[i]) {
            cout << i;
            return;
        }
    }
    cout << -1;
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