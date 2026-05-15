/*
D. 序列配对差值
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 13:46:03
user: playa
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
typedef pair<int, int> pi;

void justdoit() {
    int n, p, q, s;
    cin >> n >> p >> q >> s;
    if (n > p || n > q) {
        cout << -1;
        return;
    }
    vector<int> a(p);
    vector<int> b(q);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    int res = INF;
    int t = 1000;
    clock_t st = clock();
    sort(all(a));
    sort(all(b));
    mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    auto start = chrono::steady_clock::now();
    const long long LIMIT_US = 450000; 
    while (1) {
        long long used = chrono::duration_cast<chrono::microseconds>(
                            chrono::steady_clock::now() - start).count();
        if (used >= LIMIT_US) break;
        int cnt = 0;
        int ans = -INF;
        for (int i = 0; i < p || i < q; i++) {
            if (a[i] + b[i] <= s) {
                cnt++;
                if (abs(a[i] - b[i]) > ans) {
                    ans = abs(a[i] - b[i]);
                }
            } else {
                break;
            }
            if (cnt == n) break;
        }
        if (cnt == n && ans < res) {
            res = ans;
        }
        shuffle(all(a), rng);
        shuffle(all(b), rng);
    }
    if (res == INF) {
        cout << -1;
        return;
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