/*
5SumZero
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 15:38:26
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
    int n[5];
    rep(i, 5) {
        cin >> n[i];
    }
    vector<vector<int>> a(5);
    rep(i, 5) {
        a[i].resize(n[i]);
    }
    rep(i, 5) {
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
        }
    }
    map<int, int> bcd;
    for (int i = 0; i < n[2]; i++) {
        for (int j = 0; j < n[3]; j++) {
            for (int k = 0; k < n[4]; k++) {
                int sum = a[2][i] + a[3][j] + a[4][k];
                debug(i, j, k);
                if (bcd.count(sum)) bcd[sum]++;
                else bcd[sum] = 1;
            }
        }
    }
    debug(bcd);
    int res = 0;
    for (int i = 0; i < n[0]; i++) {
        for (int j = 0; j < n[1]; j++) {
            int sum = a[0][i] + a[1][j];
            if (bcd.count(-sum)) {
                res += bcd[-sum];
            }
        }
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