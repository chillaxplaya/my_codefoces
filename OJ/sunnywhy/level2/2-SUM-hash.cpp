/*
2-SUM-hash
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 14:08:26
*/
#include <bits/stdc++.h>
#include <unordered_set>
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
    unordered_set<int> Set;
    int n, k, x, res = 0;
    cin >> n >> k;
    rep (i, n) {
        cin >> x;
        if (Set.count(k - x)) {
            res++;
        }
        Set.insert(x);
    }
    cout << res;
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