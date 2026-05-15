/*
最小右移
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-08 18:50:21
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
    vector<int> b(n);
    int i = n - 1;
    int j = n - 1;
    for (auto &e : a) {
        cin >> e;
    }
    for (auto &e : b) {
        cin >> e;
    }
    while(i >= 0 && j >= 0) {
        if (a[i] >= b[j]) {
            i--;
            j--;
        } else {
            j--;
        }
    }
    debug(i, j);
    cout << i - j;
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