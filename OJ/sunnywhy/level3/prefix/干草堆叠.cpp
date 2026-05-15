/*
干草堆叠
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 16:59:17
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
    int l, r;
    cin >> n >> k;
    vector<int> sec(n + 2);
    vector<int> res;
    rep(i, k) {
        cin >> l >> r;
        sec[l]++;
        sec[r + 1]--;
    }
    int presum = 0;
    for (int i = 1; i <= n; i++) {

        presum += sec[i];
        debug(presum);
        res.push_back(presum);
    }
    sort(res.begin(), res.end());
    cout << res[n / 2];
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